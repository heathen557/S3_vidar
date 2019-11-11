#ifndef RECESERIAL_MSG_H
#define RECESERIAL_MSG_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include<QDebug>
#include<QDataStream>
#include<vector>
#include<QTimer>
#include<QList>

using namespace std;


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


class receSerial_msg : public QObject
{
    Q_OBJECT
public:
    explicit receSerial_msg(QObject *parent = 0);

    QSerialPort *serial;

    QByteArray m_buffer;

    vector<int> tofPeak_vector;

    int sample_range;

    int tof_offset;

    int ratio;

    bool isTranslateFlag;     //解析数据 还是直接显示16进制的 切换标识 true：则对数据进行解析

    bool withOrNotPeakFlag;   //是否要带peak的解析标识

    bool peak_disp_mode;

    vector<float> PlotData_vector;           //plot相关
    vector<float> StatisticData_vector;      //统计相关
    QStringList   DistanceStr;            //显示tof peak相关


signals:
    void dealedData_signal(QString,vector<float>,vector<float>);     //当前的tof值 ; plotData ; statisticData

    void showResultMsg_signal(QStringList);  //显示tof peak相关  主界面显示;  主线程中设定一个暂存变量，每秒钟在result窗口中显示append(),然后清空result

    void returnLinkInfo_signal(QString, bool);

public slots:
    void readDataSlot();

    bool msgCheck(QString msg);

    void openOrCloseSerial_slot(bool);
};

#endif // RECESERIAL_MSG_H
