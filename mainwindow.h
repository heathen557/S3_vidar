﻿#ifndef MAINWINDOW_H
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
#include<qcustomplot.h>
#include<calhistogram_obj.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initUILanguage();

    void initSerial();

    void initConnect();

    void initStatisticUI();

    void keyPressEvent(QKeyEvent *e);

    receSerial_msg  *receSerial_Obj;      //串口接收数据线程

    QThread *receSerialThread;

    calHistogram_obj  *calHis_obg;        //计算统计直方图的线程

    QThread *calHisThread;


    bool isLinked;

    QTimer showTimer;                  //暂定为30ms

    QTimer oneSecondTimer;            //1秒钟的定时器

    QString DistanceStrCurrent;        //当前距离

    float DistanceMean;

    float DistanceStd;

    QStringList DistanceStr;               //要显示的tof/peak的字符串，或者显示16进制数据

    vector<double> PlotData_vector;           //plot相关

    vector<double> StatisticData_vector;      //统计相关

    bool isTranslateFlag;     //解析数据 还是直接显示16进制的 切换标识 true：则对数据进行解析

    int Count_num;            //每秒显示记录的条数

    int allCountNum;

    int Count_num_lastSec;    //上一秒钟收到记录的条数

    bool isTimelySaveFlag;

    int tumlySaveCnt;

    int generateCnt;

    bool plot_Mode;           //是否显示统计图的标识，默认为false，也就是不显示，

    QTimer plotShowTimer;     //plot显示的 定时器  20ms

    int plot_type;            //0：显示TOF   1：显示直方图His

    QCPBars *regen;          //直方图用   *****标签相关

    int index;



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

    void dealedData_slot(QString,vector<double>,vector<double>);   //接收处理数据线程数据的槽函数

    void showTimerSlot();

    void beginTimer();

    void stopTimer();

    void on_selectSavePathtoolButton_clicked();

    void oneSecondTimer_slot();

    void on_TimingSave_checkBox_clicked();

    void on_clear_pushButton_clicked();

    void on_timeInnterval_lineEdit_returnPressed();

    void on_portScan_pushButton_clicked();

    void on_noPeak_radioButton_clicked();

    void on_withPeak_radioButton_clicked();

    void showResultMsg_slot(QStringList);    //接收界面的要显示的tof和peak信息,每一秒钟显示一次，然后清空暂存变量

    void plotShowTimer_slot();

    void on_TOF_radioButton_clicked();

    void on_Histogram_radioButton_clicked();

    void returnLinkInfo_slot(QString, bool);

    void toShowHistogram_slot(QVector<double>,QVector<double>,QVector<QString>,int ,int );   //显示统计直方图



    void on_savePicture_pushButton_clicked();

signals:
    void openOrCloseSerial_signal(bool);     //true:open   false：close

    void calHistogram_signal(vector<double>);    //begin histogram signal()

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
