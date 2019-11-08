#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QDebug>
#include<receserial_msg.h>
#include<QThread>
#include<QTimer>
#include<QFileDialog>
#include<QDateTime>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initSerial();

    void initConnect();

    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
        bool localEchoEnabled;
    };

    Settings currentSettings;

    receSerial_msg  *receSerial_Obj;

    QThread *receSerialThread;

    bool isLinked;

    QTimer showTimer;

    QString DistanceStrCurrent;        //当前距离

    float DistanceMean;

    float DistanceStd;

    QStringList DistanceStr;               //要显示的tof/peak的字符串，或者显示16进制数据

    vector<float> PlotData_vector;           //plot相关

    vector<float> StatisticData_vector;      //统计相关

    bool isTranslateFlag;     //解析数据 还是直接显示16进制的 切换标识 true：则对数据进行解析

    int Count_num;            //显示记录的条数

private slots:
    void on_save_pushButton_clicked();

    void on_plotSet_on_radioButton_clicked();

    void on_plotSet_off_radioButton_clicked();

    void on_openPort_pushButton_clicked();

    void portOnSetting();

    void portOffSetting();

    void on_averageSample_lineEdit_returnPressed();

    void on_Ratio_lineEdit_returnPressed();

    void on_offset_lineEdit_returnPressed();

    void on_Transform_checkBox_clicked();

    void on_PeakSet_on_radioButton_clicked();

    void on_PeakSet_off_radioButton_clicked();

    void dealedData_slot(QString,vector<float>,vector<float>);   //接收处理数据线程数据的槽函数

    void showTimerSlot();

    void beginTimer();

    void stopTimer();

    void on_selectSavePathtoolButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
