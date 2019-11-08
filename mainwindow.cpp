#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    qRegisterMetaType<vector<float>>("vector<float>");   //注册函数
    qRegisterMetaType<vector<int>>("vector<int>");       //注册函数

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


    //初始化偏移 等参数
    receSerial_Obj->sample_range = ui->averageSample_lineEdit->text().toInt();
    receSerial_Obj->ratio = ui->Ratio_lineEdit->text().toInt();
    receSerial_Obj->tof_offset = ui->offset_lineEdit->text().toInt();


    initSerial();
    isLinked = false;
    isTranslateFlag = true;
    Count_num = 0;
    Count_num_lastSec = 0;
    isTimelySaveFlag = false;
}

void MainWindow::initConnect()
{
    //接收数据线程 接收并处理数据后，将处理结果发送给主线程的信号与槽
    connect(receSerial_Obj,SIGNAL(dealedData_signal(QString,vector<float>,vector<float>)),this,SLOT(dealedData_slot(QString,vector<float>,vector<float>)));

    //刷新定时器 信号与槽的连接
    connect(&showTimer,SIGNAL(timeout()),this,SLOT(showTimerSlot()));
    connect(&oneSecondTimer,SIGNAL(timeout),this,SLOT(oneSecondTimer_slot()));

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


    QStringList comList;//串口号
    comList.clear();
    comList<<"COM1"<<"COM2"<<"COM3"<<"COM4"<<"COM5"<<"COM6"
          <<"COM7"<<"COM8"<<"COM9"<<"COM10"<<"COM11"<<"COM12"
         <<"COM13"<<"COM14"<<"COM15"<<"COM16"<<"COM17"<<"COM18"
        <<"COM19"<<"COM20"<<"COM21"<<"COM22"<<"COM23"<<"COM24"
       <<"COM25"<<"COM26"<<"COM27"<<"COM28"<<"COM28"<<"COM29"<<"COM30";
    ui->serialPortInfoListBox->clear();
    ui->serialPortInfoListBox->addItems(comList);
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



        receSerial_Obj->serial->setPortName(currentSettings.name);
        receSerial_Obj->serial->setBaudRate(currentSettings.baudRate);
        receSerial_Obj->serial->setDataBits(currentSettings.dataBits);
        receSerial_Obj->serial->setParity(currentSettings.parity);
        receSerial_Obj->serial->setStopBits(currentSettings.stopBits);
        receSerial_Obj->serial->setFlowControl(currentSettings.flowControl);
        if (receSerial_Obj->serial->open(QIODevice::ReadWrite)) {
            isLinked = true;
             ui->serialPortInfoListBox->setEnabled(false);
             ui->baudRateBox->setEnabled(false);
             ui->dataBitsBox->setEnabled(false);
             ui->parityBox->setEnabled(false);
             ui->stopBitsBox->setEnabled(false);

             portOffSetting();

        } else {
            isLinked = false;
            QMessageBox::critical(this, QStringLiteral("告警"), QStringLiteral("打开串口失败！"));
            return;

        }

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

        ui->openPort_pushButton->setText("ClosePort");
        beginTimer();
    }
    else
    {
        receSerial_Obj->serial->close();
        stopTimer();
        ui->openPort_pushButton->setText("OpenPort");
        ui->serialPortInfoListBox->setEnabled(true);
        ui->baudRateBox->setEnabled(true);
        ui->dataBitsBox->setEnabled(true);
        ui->parityBox->setEnabled(true);
        ui->stopBitsBox->setEnabled(true);
        portOnSetting();
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


//show plot
void MainWindow::on_plotSet_on_radioButton_clicked()
{
    ui->groupBox_2->setVisible(true);
    ui->groupBox_9->setVisible(true);
}
//hide plot
void MainWindow::on_plotSet_off_radioButton_clicked()
{
    ui->groupBox_2->setVisible(false);
     ui->groupBox_9->setVisible(false);
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
void MainWindow::dealedData_slot(QString currTof,vector<float> plotData, vector<float> StatisticData)
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
    DistanceStr.clear();
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


