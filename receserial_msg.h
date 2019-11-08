#ifndef RECESERIAL_MSG_H
#define RECESERIAL_MSG_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include<QDebug>
#include<QDataStream>
#include<vector>
#include<QTimer>

using namespace std;

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

    bool peak_disp_mode;

    vector<float> PlotData_vector;           //plot相关
    vector<float> StatisticData_vector;      //统计相关
    QStringList   DistanceStr;            //显示tof peak相关


signals:
    void dealedData_signal(QString,vector<float>,vector<float>);

public slots:
    void readDataSlot();

    bool msgCheck(QString msg);
};

#endif // RECESERIAL_MSG_H
