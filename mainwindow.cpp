#include "mainwindow.h"
#include "ui_mainwindow.h"


Settings currentSettings;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->ResultHistory_textEdit->document()->setMaximumBlockCount(100000);    //最多显示10000行，滑动存储  10w

    qRegisterMetaType<vector<double>>("vector<double>");   //注册函数
    qRegisterMetaType<vector<int>>("vector<int>");       //注册函数
    qRegisterMetaType<QVector<double>>("QVector<double>");   //注册函数
    qRegisterMetaType<QVector<QString>>("QVector<QString>");   //注册函数

    ui->splitter->setStretchFactor(0,2);
    ui->splitter->setStretchFactor(1,5);
    ui->splitter->setStretchFactor(1,5);
    ui->groupBox_2->setVisible(false);
    ui->groupBox_9->setVisible(false);

    ui->savePath_lineEdit->setReadOnly(true);
    ui->timeInnterval_label->setEnabled(false);
    ui->timeInnterval_lineEdit->setEnabled(false);

    receSerial_Obj = new receSerial_msg;;
    receSerialThread = new QThread;
    receSerial_Obj->moveToThread(receSerialThread);
    receSerialThread->start();



    calHis_obg = new calHistogram_obj;
    calHisThread = new QThread;
    calHis_obg->moveToThread(calHisThread);
    calHisThread->start();


    //初始化偏移 等参数
    receSerial_Obj->sample_range = ui->averageSample_lineEdit->text().toInt();
    receSerial_Obj->ratio = ui->Ratio_lineEdit->text().toInt();
    receSerial_Obj->tof_offset = ui->offset_lineEdit->text().toInt();



    isLinked = false;
    isTranslateFlag = true;
    Count_num = 0;
    Count_num_lastSec = 0;
    isTimelySaveFlag = false;
    plot_Mode = false;      //默认不显示统计图
    plot_type = 0;     //默认显示TOF
    initSerial();
    initStatisticUI();
    initConnect();

}

void MainWindow::initConnect()
{
    //接收数据线程 接收并处理数据后，将处理结果发送给主线程的信号与槽
    connect(receSerial_Obj,SIGNAL(dealedData_signal(QString,vector<double>,vector<double>)),this,SLOT(dealedData_slot(QString,vector<double>,vector<double>)));
    connect(receSerial_Obj,SIGNAL(showResultMsg_signal(QStringList)),SLOT(showResultMsg_slot(QStringList)));
    //link info slot
    connect(this,SIGNAL(openOrCloseSerial_signal(bool)),receSerial_Obj,SLOT(openOrCloseSerial_slot(bool)));
    connect(receSerial_Obj,SIGNAL(returnLinkInfo_signal(QString, bool)),this,SLOT(returnLinkInfo_slot(QString, bool)));

    // calculate histogram connect
    connect(this,SIGNAL(calHistogram_signal(vector<double>)),calHis_obg,SLOT(calHistogram_slot(vector<double>)));
    connect(calHis_obg,SIGNAL(toShowHistogram_signal(QVector<double>,QVector<double>,QVector<QString>,int ,int )),this,SLOT(toShowHistogram_slot(QVector<double>,QVector<double>,QVector<QString>,int ,int )));

    //刷新定时器 信号与槽的连接
    connect(&showTimer,SIGNAL(timeout()),this,SLOT(showTimerSlot()));
    connect(&oneSecondTimer,SIGNAL(timeout()),this,SLOT(oneSecondTimer_slot()));
    connect(&plotShowTimer,SIGNAL(timeout()),this,SLOT(plotShowTimer_slot()));

}


void MainWindow::initStatisticUI()
{
    QString demoName = "Histogram";//实例名称
    // set dark background gradient: 设置暗背景渐变
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));//开始颜色为黑色
    gradient.setColorAt(0.38, QColor(200, 105, 105));//红色
    gradient.setColorAt(1, QColor(70, 70, 70));//黑色
    //tof统计相关
//    ui->TOF_widget->setBackground(QBrush(gradient));//设置图表背景（用画刷设置）
    ui->TOF_widget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom| QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables);

    ui->TOF_widget->legend->setVisible(true);
    ui->TOF_widget->legend->setFont(QFont("Helvetica", 9));
    ui->TOF_widget->yAxis->setRange(0,500);
    ui->TOF_widget->xAxis->setRange(0,256);
    ui->TOF_widget->addGraph();
    ui->TOF_widget->graph(0)->setName(QStringLiteral("TOF"));

    //Histgram统计相关

//    ui->Histogram_widget->setBackground(QBrush(gradient));//设置图表背景（用画刷设置）


    regen = new QCPBars(ui->Histogram_widget->xAxis, ui->Histogram_widget->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(2);
    regen->setName("Regenerative");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));

    ui->Histogram_widget->xAxis->setTickLabelRotation(60);//设置标签角度旋转
    ui->Histogram_widget->xAxis->setSubTicks(false);//设置是否显示子标签
    ui->Histogram_widget->xAxis->setTickLength(0, 4);
    ui->Histogram_widget->xAxis->setRange(0, 500);     //设置x轴区间
    ui->Histogram_widget->xAxis->setBasePen(QPen(Qt::black));
    ui->Histogram_widget->xAxis->setTickPen(QPen(Qt::black));
    ui->Histogram_widget->xAxis->grid()->setVisible(true);//设置网格是否显示
    ui->Histogram_widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->Histogram_widget->xAxis->setTickLabelColor(Qt::black);//设置标记标签颜色
    ui->Histogram_widget->xAxis->setLabelColor(Qt::black);

    // prepare y axis: //设置y轴
    ui->Histogram_widget->yAxis->setRange(0, 800);
    ui->Histogram_widget->yAxis->setPadding(5); // a bit more space to the left border 设置左边留空间
//    ui->Histogram_widget->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");
    ui->Histogram_widget->yAxis->setBasePen(QPen(Qt::black));
    ui->Histogram_widget->yAxis->setTickPen(QPen(Qt::black));
    ui->Histogram_widget->yAxis->setSubTickPen(QPen(Qt::black));//设置SubTick颜色，SubTick指的是轴上的
                                                      //刻度线
    ui->Histogram_widget->yAxis->grid()->setSubGridVisible(true);
    ui->Histogram_widget->yAxis->setTickLabelColor(Qt::black);//设置标记标签颜色（y轴标记标签）
    ui->Histogram_widget->yAxis->setLabelColor(Qt::black);//设置标签颜色（y轴右边标签）
    ui->Histogram_widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->Histogram_widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


    // setup legend: 设置标签
//    ui->Histogram_widget->legend->setVisible(true);
    ui->Histogram_widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->Histogram_widget->legend->setBrush(QColor(255, 255, 255, 100));
    ui->Histogram_widget->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->Histogram_widget->legend->setFont(legendFont);
    ui->Histogram_widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);//设置 可拖动，可放大缩





}

void MainWindow::beginTimer()
{
    showTimer.start(50);
    oneSecondTimer.start(1000);
}

void MainWindow::stopTimer()
{
    showTimer.stop();
    oneSecondTimer.stop();
}


//查找可用的端口
void MainWindow::on_portScan_pushButton_clicked()
{
    QStringList m_serialPortName;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        m_serialPortName << info.portName();
        qDebug()<<"serialPortName:"<<info.portName();
    }
    ui->serialPortInfoListBox->clear();
    ui->serialPortInfoListBox->addItems(m_serialPortName);
    QMessageBox::information(NULL,QStringLiteral("提示"),QStringLiteral("可用端口检测完毕！"));
}


//串口初始化
void MainWindow::initSerial()
{
    QFile file("setting.ini");
    QByteArray temp("\r\n");
    QString line[20];

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        int i = 0;
        while (!in.atEnd())
        {
            line[i] = in.readLine();
            i++;
        }
        file.close();
    }
    int numSeri_ = line[0].toInt();       //串口号
    int baudRateBox_ = line[1].toInt();   //波特率


//    QStringList comList;//串口号
//    comList.clear();
//    comList<<"COM1"<<"COM2"<<"COM3"<<"COM4"<<"COM5"<<"COM6"
//          <<"COM7"<<"COM8"<<"COM9"<<"COM10"<<"COM11"<<"COM12"
//         <<"COM13"<<"COM14"<<"COM15"<<"COM16"<<"COM17"<<"COM18"
//        <<"COM19"<<"COM20"<<"COM21"<<"COM22"<<"COM23"<<"COM24"
//       <<"COM25"<<"COM26"<<"COM27"<<"COM28"<<"COM28"<<"COM29"<<"COM30";

//    ui->serialPortInfoListBox->setCurrentIndex(numSeri_);

    int num = 0;
    QStringList m_serialPortName;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        num++;
        m_serialPortName << info.portName();
        qDebug()<<"serialPortName:"<<info.portName();
    }
    ui->serialPortInfoListBox->clear();
    ui->serialPortInfoListBox->addItems(m_serialPortName);
    if(numSeri_>num)
        ui->serialPortInfoListBox->setCurrentIndex(0);
    else
        ui->serialPortInfoListBox->setCurrentIndex(numSeri_);



    ui->baudRateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudRateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudRateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudRateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->baudRateBox->addItem(QStringLiteral("256000"), QSerialPort::Baud256000);
    ui->baudRateBox->addItem(tr("Custom"));
    ui->baudRateBox->setCurrentIndex(baudRateBox_);

    ui->dataBitsBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->dataBitsBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->dataBitsBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->dataBitsBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->dataBitsBox->setCurrentIndex(3);

    ui->parityBox->addItem(tr("None"), QSerialPort::NoParity);
    ui->parityBox->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->parityBox->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->parityBox->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->parityBox->addItem(tr("Space"), QSerialPort::SpaceParity);

    ui->stopBitsBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    ui->stopBitsBox->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
#endif
    ui->stopBitsBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);
}

//打开串口
void MainWindow::on_openPort_pushButton_clicked()
{
    if(ui->openPort_pushButton->text() == "OpenPort")
    {
        currentSettings.name = ui->serialPortInfoListBox->currentText();

        if (ui->baudRateBox->currentIndex() == 4) {
            currentSettings.baudRate = ui->baudRateBox->currentText().toInt();
        } else {
            currentSettings.baudRate = static_cast<QSerialPort::BaudRate>(
                        ui->baudRateBox->itemData(ui->baudRateBox->currentIndex()).toInt());
        }
        currentSettings.stringBaudRate = QString::number(currentSettings.baudRate);

        currentSettings.dataBits = static_cast<QSerialPort::DataBits>(
                    ui->dataBitsBox->itemData(ui->dataBitsBox->currentIndex()).toInt());
        currentSettings.stringDataBits = ui->dataBitsBox->currentText();

        currentSettings.parity = static_cast<QSerialPort::Parity>(
                    ui->parityBox->itemData(ui->parityBox->currentIndex()).toInt());
        currentSettings.stringParity = ui->parityBox->currentText();

        currentSettings.stopBits = static_cast<QSerialPort::StopBits>(
                    ui->stopBitsBox->itemData(ui->stopBitsBox->currentIndex()).toInt());
        currentSettings.stringStopBits = ui->stopBitsBox->currentText();

//         qDebug()<<"name="<<currentSettings.name<<" baudRate ="<<currentSettings.baudRate<<" dataBits="<<currentSettings.dataBits<<" parity="<<currentSettings.parity<<" stopBits="<<currentSettings.stopBits<<" flowCon"<<currentSettings.flowControl;


        emit openOrCloseSerial_signal(true);

//        receSerial_Obj->serial->setPortName(currentSettings.name);
//        receSerial_Obj->serial->setBaudRate(currentSettings.baudRate);
//        receSerial_Obj->serial->setDataBits(currentSettings.dataBits);
//        receSerial_Obj->serial->setParity(currentSettings.parity);
//        receSerial_Obj->serial->setStopBits(currentSettings.stopBits);
//        receSerial_Obj->serial->setFlowControl(currentSettings.flowControl);
//        if (receSerial_Obj->serial->open(QIODevice::ReadWrite)) {
//            isLinked = true;
//             ui->serialPortInfoListBox->setEnabled(false);
//             ui->baudRateBox->setEnabled(false);
//             ui->dataBitsBox->setEnabled(false);
//             ui->parityBox->setEnabled(false);
//             ui->stopBitsBox->setEnabled(false);

//             portOffSetting();

//        } else {
//            isLinked = false;
//            QMessageBox::critical(this, QStringLiteral("告警"), QStringLiteral("打开串口失败！"));
//            return;

//        }

        qDebug()<<"name="<<currentSettings.name<<" baudRate ="<<currentSettings.baudRate<<" dataBits="<<currentSettings.dataBits<<" parity="<<currentSettings.parity<<" stopBits="<<currentSettings.stopBits<<" flowCon"<<currentSettings.flowControl;


        QFile file("setting.ini");
        QByteArray temp("\r\n");
        QString line[20];

        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream in(&file);
            int i = 0;
            while (!in.atEnd())
            {
                line[i] = in.readLine();
                i++;
            }
            file.close();
        }

        int seriNum = ui->serialPortInfoListBox->currentIndex();
        int baudBox = ui->baudRateBox->currentIndex();


        if(file.open(QIODevice::WriteOnly))
        {
            QByteArray writeData;
            writeData = QString::number(seriNum).toLatin1()+ temp + QString::number(baudBox).toLatin1()+temp+\
                    line[2].toLatin1()+ temp +line[3].toLatin1()+ temp+ line[4].toLatin1()+ temp +line[5].toLatin1();
            if (-1 == file.write(writeData))
            {
                qDebug()<<"ERROR";
            }
            file.close();
        }

//        ui->openPort_pushButton->setText("ClosePort");
//        beginTimer();
    }
    else
    {
        emit openOrCloseSerial_signal(false);
//        receSerial_Obj->serial->close();
//        stopTimer();
//        ui->openPort_pushButton->setText("OpenPort");
//        ui->serialPortInfoListBox->setEnabled(true);
//        ui->baudRateBox->setEnabled(true);
//        ui->dataBitsBox->setEnabled(true);
//        ui->parityBox->setEnabled(true);
//        ui->stopBitsBox->setEnabled(true);
//        portOnSetting();
    }


}

void MainWindow::returnLinkInfo_slot(QString str, bool flag)
{
    if("open" == str)
    {
        if(true == flag)
        {
             isLinked = true;
             ui->serialPortInfoListBox->setEnabled(false);
             ui->baudRateBox->setEnabled(false);
             ui->dataBitsBox->setEnabled(false);
             ui->parityBox->setEnabled(false);
             ui->stopBitsBox->setEnabled(false);
             ui->openPort_pushButton->setText("ClosePort");
             beginTimer();
        }else
        {
            QMessageBox::critical(this, QStringLiteral("告警"), QStringLiteral("打开串口失败！"));
        }
    }else
    {
        if(true == flag)
        {
            isLinked = false;
            stopTimer();
            ui->openPort_pushButton->setText("OpenPort");
            ui->serialPortInfoListBox->setEnabled(true);
            ui->baudRateBox->setEnabled(true);
            ui->dataBitsBox->setEnabled(true);
            ui->parityBox->setEnabled(true);
            ui->stopBitsBox->setEnabled(true);
            portOnSetting();
        }else
        {
            QMessageBox::critical(this, QStringLiteral("告警"), QStringLiteral("关闭串口失败！"));
        }
    }
}



void MainWindow::portOnSetting()
{
    ui->noPeak_radioButton->setEnabled(true);
    ui->withPeak_radioButton->setEnabled(true);
}

void MainWindow::portOffSetting()
{
    ui->noPeak_radioButton->setEnabled(false);
    ui->withPeak_radioButton->setEnabled(false);
}




MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_averageSample_lineEdit_returnPressed()
{
    receSerial_Obj->sample_range = ui->averageSample_lineEdit->text().toInt();
    qDebug()<<"receSerial_Obj->sample_range = "<<receSerial_Obj->sample_range;
}

void MainWindow::on_Ratio_lineEdit_returnPressed()
{
    receSerial_Obj->ratio = ui->Ratio_lineEdit->text().toInt();
    qDebug()<<"receSerial_Obj->ratio = "<<receSerial_Obj->ratio;

}

void MainWindow::on_offset_lineEdit_returnPressed()
{
    receSerial_Obj->tof_offset = ui->offset_lineEdit->text().toInt();
    qDebug()<<"receSerial_Obj->tof_offset = "<<receSerial_Obj->tof_offset;

}

//是否进行进制转换的槽函数
void MainWindow::on_Transform_checkBox_clicked()
{
    if( ui->Transform_checkBox->isChecked())
    {
        qDebug()<<" checked is true";
        receSerial_Obj->isTranslateFlag = true;
    }else{
        qDebug()<<" checked is false";
        receSerial_Obj->isTranslateFlag = false;
    }
}


//显示peak的值
void MainWindow::on_PeakSet_on_radioButton_clicked()
{
    if(ui->PeakSet_on_radioButton->isChecked())
    {
        qDebug()<<"PeakSet_on_radioButton checked!! "<<endl;
        receSerial_Obj->peak_disp_mode = true;
    }

}

//不显示peak的值
void MainWindow::on_PeakSet_off_radioButton_clicked()
{
    if(ui->PeakSet_off_radioButton->isChecked())
    {
        qDebug()<<" PeakSet_on_radioButton cancel checked!";
        receSerial_Obj->peak_disp_mode = false;
    }
}


//接收处理数据线程数据的槽函数
void MainWindow::dealedData_slot(QString currTof,vector<double> plotData, vector<double> StatisticData)
{
    DistanceStrCurrent = currTof;

    PlotData_vector = plotData;           //plot相关

    StatisticData_vector = StatisticData;      //统计相关
}

//定时器的槽函数
void MainWindow::showTimerSlot()
{
    //显示当前的距离
    ui->currentDistance_label->setText(DistanceStrCurrent);

    //计算tof的均值
    int len = StatisticData_vector.size();
    if(len<1)
        return;
    DistanceMean = std::accumulate(std::begin(StatisticData_vector),std::end(StatisticData_vector),0.0)/len;
    ui->mean_label->setText(QString::number(DistanceMean));

    //计算tof的方差
    float tofAccum = 0.0;
    std::for_each (std::begin(StatisticData_vector), std::end(StatisticData_vector), [&](const double d) {
            tofAccum  += (d-DistanceMean)*(d-DistanceMean);
        });
    DistanceStd = sqrt(tofAccum/(len-1));
    ui->std_label->setText(QString::number(DistanceStd));


    //text_BOX上面的数据显示   分为显示解析后的TOF数据 或者16进制的数据  ;看是否需要判断 isTranslateFlag
    for(int i=0 ;i<DistanceStr.length();i++ )
    {
        Count_num++;
        ui->ResultHistory_textEdit->append(DistanceStr[i]);
    }
    DistanceStr.clear();    //清空暂存的变量
    ui->HistoryData_label->setText(QString::number(Count_num));   //显示记录条数

}

//选择文件的保存路径
void MainWindow::on_selectSavePathtoolButton_clicked()
{
    QString file_path = QFileDialog::getExistingDirectory(this,QStringLiteral("请选择文件保存路径..."),"./");
    if(file_path.isEmpty())
    {
       qDebug()<<QStringLiteral("没有选择路径")<<endl;
       QMessageBox::information(NULL,QStringLiteral("告警"),QStringLiteral("保存路径不能为空"));
        return;
    }
    else
    {
        file_path.append("/");
        qDebug() << file_path << endl;
        ui->savePath_lineEdit->setText(file_path);
    }
}


//选中文件保存功能
void MainWindow::on_save_pushButton_clicked()
{

    QString text = ui->ResultHistory_textEdit->toPlainText();

    QString sFilePath = ui->savePath_lineEdit->text() ;
    QDateTime currTime = QDateTime::currentDateTime();
    QString fileName = currTime.toString("yyyyMMdd_hh_mm_ss");
    fileName.append(".txt");
    sFilePath.append(fileName);     //加上文件名


    QFile file(sFilePath);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out<<text.toLocal8Bit()<<endl;
    file.close();

    QString strMsg = QStringLiteral("已保存在指定路径下，文件名为：") + fileName;
    QMessageBox::information(NULL,QStringLiteral("提示"),strMsg);
}


//接收串口处理线程发送来的用于界面上显示的字符串连接
void MainWindow::showResultMsg_slot(QStringList DisStr)
{
    DistanceStr = DisStr;
}

//每秒钟刷新的槽函数
void MainWindow::oneSecondTimer_slot()
{
    int dps = Count_num - Count_num_lastSec;
    if(dps > 0)
    {
        ui->DPS_label->setText(QString::number(dps));
    }else
    {
        ui->DPS_label->setText("0");
    }
    Count_num_lastSec = Count_num;


    if(isTimelySaveFlag)     //60s存一帧数据
    {
        tumlySaveCnt--;
        if(0 == tumlySaveCnt)
        {
            tumlySaveCnt = ui->timeInnterval_lineEdit->text().toInt();
            QString textBox_Data = ui->ResultHistory_textEdit->toPlainText();
            if(!textBox_Data.isEmpty())
            {
                QString filePathName = ui->savePath_lineEdit->text() +"AutoSave" +QString::number(generateCnt)+".txt";  //文件名
                QFile file(filePathName);
                file.open(QIODevice::WriteOnly|QIODevice::Text);
                QTextStream out(&file);
                out<<textBox_Data.toLocal8Bit()<<endl;
                file.close();

                generateCnt++;
                ui->ResultHistory_textEdit->clear(); //清空控件上的数据
            }

        }

    }
}


//TimeingSave_checkBox的点击的槽函数
void MainWindow::on_TimingSave_checkBox_clicked()
{
    if(ui->TimingSave_checkBox->isChecked())
    {
        isTimelySaveFlag = true;
        ui->timeInnterval_label->setEnabled(true);
        ui->timeInnterval_lineEdit->setEnabled(true);
        tumlySaveCnt = ui->timeInnterval_lineEdit->text().toInt();
        generateCnt = 0;
        ui->save_pushButton->setEnabled(false);
    }
    else
    {
        isTimelySaveFlag = false;
        ui->timeInnterval_label->setEnabled(false);
        ui->timeInnterval_lineEdit->setEnabled(false);
        ui->save_pushButton->setEnabled(true);
    }

}

//改变tumlySaveCnt的槽函数
void MainWindow::on_timeInnterval_lineEdit_returnPressed()
{
    tumlySaveCnt = ui->timeInnterval_lineEdit->text().toInt();
}

//clear清空函数
void MainWindow::on_clear_pushButton_clicked()
{

    ui->ResultHistory_textEdit->clear();
    Count_num = 0;
}



// no Peak radioButton checked
void MainWindow::on_noPeak_radioButton_clicked()
{
    receSerial_Obj->withOrNotPeakFlag = false;
    ui->groupBox_6->setEnabled(false);
}

// with Peak radioButton checked
void MainWindow::on_withPeak_radioButton_clicked()
{
    receSerial_Obj->withOrNotPeakFlag = true;
    ui->groupBox_6->setEnabled(true);
}

//显示TOF的统计信息
void MainWindow::on_TOF_radioButton_clicked()
{
    if(plotShowTimer.isActive())
        plotShowTimer.stop();
    plotShowTimer.start(20);

    plot_type = 0;
    ui->stackedWidget->setCurrentIndex(0);


}

//显示统计直方图   由于耗时严重，由专门的线程进行处理
void MainWindow::on_Histogram_radioButton_clicked()
{
    if(plotShowTimer.isActive())
        plotShowTimer.stop();
    plotShowTimer.start(200);      //定时器改为200ms进行一次刷新

    plot_type = 1;
    ui->stackedWidget->setCurrentIndex(1);
}


//show plot
void MainWindow::on_plotSet_on_radioButton_clicked()
{
    plotShowTimer.start(20);
    plot_Mode = true;
    ui->groupBox_2->setVisible(true);

}
//hide plot
void MainWindow::on_plotSet_off_radioButton_clicked()
{
    plotShowTimer.stop();
    plot_Mode = false;
    ui->groupBox_2->setVisible(false);

}


//显示统计信息的槽函数 20ms刷新一次
void MainWindow::plotShowTimer_slot()
{
    QVector<double> label_x(20000);
    QVector<double> tofValue(20000);

    float labelMax = 0;
    float valueMax = 0;
    if(plot_Mode)   //用户选中了显示统计信息的模式
    {
        if(0 == plot_type)          //显示tof的统计信息
        {
            int len = PlotData_vector.size();
            if(len<1)
                return;
            for(int i=0; i< len; i++)
            {
                label_x[i] = i;
                tofValue[i] = PlotData_vector[i];

                valueMax = valueMax>tofValue[i] ? valueMax:tofValue[i];    //统计tof的最大值，方便显示
            }
            labelMax = PlotData_vector.size();

            ui->TOF_widget->xAxis->setRange(0,labelMax);
            ui->TOF_widget->yAxis->setRange(0,valueMax+10);
            ui->TOF_widget->graph(0)->setData(label_x,tofValue);
            ui->TOF_widget->replot();


        }else if(1 == plot_type)    //显示直方图的信息
        {

            index++;
            vector<double> vec(20000);
            for(int i=0; i<8000; i++)
                vec[i] = 1.9;

            if(index%11==0)
            {
                for(int i=0; i<20000; i++)
                    vec[i] = 100;
            }
            vec.push_back(2.2);
            vec.push_back(1.1);
            vec.push_back(2.1);
            vec.push_back(2.1);
            vec.push_back(2.2);
            vec.push_back(1.1);
            vec.push_back(3.3);
            vec.push_back(2.1);
            vec.push_back(3.3);
//            emit calHistogram_signal(PlotData_vector);
            emit calHistogram_signal(vec);
        }
    }
}


//显示统计直方图放的槽函数
void MainWindow::toShowHistogram_slot(QVector<double> xTicks,QVector<double> numData,QVector<QString> xLabels,int xMax,int yMax)
{

//    qDebug()<<" xTicks = "<<xTicks;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
//    textTicker->addTicks(ticks, labels);
    textTicker->setTicks(xTicks, xLabels);
    ui->Histogram_widget->xAxis->setTicker(textTicker);

    ui->Histogram_widget->xAxis->setRange(0,xMax);
    ui->Histogram_widget->yAxis->setRange(0,yMax);

    regen->setData(xTicks, numData);        //只不过第一个向量xTicks的每个元素表示“第几个柱子”，然后后面对应的values表示对应“柱子的值”
    ui->Histogram_widget->replot();
}

//保存统计图像
void MainWindow::on_savePicture_pushButton_clicked()
{
    if(0 == plot_type)     //保存统计图
    {

    }else                   //保存直方图
    {

    }
}



void MainWindow::keyPressEvent(QKeyEvent *e)
{
    qDebug()<<"key num = "<<e->key();
    if(90 == e->key() && isLinked==true)
    {
        ui->groupBox_9->setVisible(true);
    }else if(88 == e->key() && isLinked==true)
    {
        ui->groupBox_9->setVisible(false);
    }
}


