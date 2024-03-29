/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QFormLayout *formLayout;
    QLabel *label_10;
    QComboBox *serialPortInfoListBox;
    QLabel *label_8;
    QComboBox *baudRateBox;
    QLabel *label_11;
    QComboBox *dataBitsBox;
    QLabel *label_7;
    QComboBox *stopBitsBox;
    QLabel *label_9;
    QComboBox *parityBox;
    QPushButton *portScan_pushButton;
    QPushButton *openPort_pushButton;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_12;
    QLabel *currentDistance_label;
    QLabel *label_14;
    QLabel *mean_label;
    QLabel *label_16;
    QLabel *std_label;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QPushButton *offsetOneByte_pushButton;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *noPeak_radioButton;
    QRadioButton *withPeak_radioButton;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_7;
    QRadioButton *PeakSet_on_radioButton;
    QRadioButton *PeakSet_off_radioButton;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_8;
    QRadioButton *plotSet_on_radioButton;
    QRadioButton *plotSet_off_radioButton;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_10;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLineEdit *averageSample_lineEdit;
    QLabel *label_4;
    QLineEdit *Ratio_lineEdit;
    QLabel *label_13;
    QLineEdit *offset_lineEdit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *HistoryData_label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLabel *DPS_label;
    QSpacerItem *horizontalSpacer;
    QCheckBox *Transform_checkBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QCheckBox *TimingSave_checkBox;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *savePath_lineEdit;
    QToolButton *selectSavePathtoolButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *save_pushButton;
    QLabel *timeInnterval_label;
    QLineEdit *timeInnterval_lineEdit;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *clear_pushButton;
    QPlainTextEdit *ResultHistory_textEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_12;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *TOF_radioButton;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *Histogram_radioButton;
    QSpacerItem *horizontalSpacer_4;
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    QCustomPlot *TOF_widget;
    QWidget *page_3;
    QGridLayout *gridLayout_13;
    QCustomPlot *Histogram_widget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *savePicture_pushButton;
    QSpacerItem *horizontalSpacer_7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1064, 706);
        QIcon icon;
        icon.addFile(QStringLiteral("icon_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setMinimumSize(QSize(220, 0));
        toolBox->setStyleSheet(QLatin1String(".QToolBox{\n"
"font: 10pt \"Times New Roman\";}"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 210, 739));
        page->setStyleSheet(QLatin1String(".QWidget{\n"
"font: 11pt \"Times New Roman\";}"));
        gridLayout_11 = new QGridLayout(page);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        groupBox_3 = new QGroupBox(page);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_10);

        serialPortInfoListBox = new QComboBox(groupBox_3);
        serialPortInfoListBox->setObjectName(QStringLiteral("serialPortInfoListBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, serialPortInfoListBox);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_8);

        baudRateBox = new QComboBox(groupBox_3);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, baudRateBox);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_11);

        dataBitsBox = new QComboBox(groupBox_3);
        dataBitsBox->setObjectName(QStringLiteral("dataBitsBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, dataBitsBox);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        stopBitsBox = new QComboBox(groupBox_3);
        stopBitsBox->setObjectName(QStringLiteral("stopBitsBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, stopBitsBox);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_9);

        parityBox = new QComboBox(groupBox_3);
        parityBox->setObjectName(QStringLiteral("parityBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, parityBox);

        portScan_pushButton = new QPushButton(groupBox_3);
        portScan_pushButton->setObjectName(QStringLiteral("portScan_pushButton"));

        formLayout->setWidget(5, QFormLayout::LabelRole, portScan_pushButton);

        openPort_pushButton = new QPushButton(groupBox_3);
        openPort_pushButton->setObjectName(QStringLiteral("openPort_pushButton"));

        formLayout->setWidget(5, QFormLayout::FieldRole, openPort_pushButton);


        gridLayout_4->addLayout(formLayout, 0, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(page);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout->addWidget(label_12);

        currentDistance_label = new QLabel(groupBox_4);
        currentDistance_label->setObjectName(QStringLiteral("currentDistance_label"));
        currentDistance_label->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));

        verticalLayout->addWidget(currentDistance_label);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout->addWidget(label_14);

        mean_label = new QLabel(groupBox_4);
        mean_label->setObjectName(QStringLiteral("mean_label"));
        mean_label->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));

        verticalLayout->addWidget(mean_label);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout->addWidget(label_16);

        std_label = new QLabel(groupBox_4);
        std_label->setObjectName(QStringLiteral("std_label"));
        std_label->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));

        verticalLayout->addWidget(std_label);


        gridLayout_5->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox_5 = new QGroupBox(page);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        offsetOneByte_pushButton = new QPushButton(groupBox_5);
        offsetOneByte_pushButton->setObjectName(QStringLiteral("offsetOneByte_pushButton"));

        gridLayout_6->addWidget(offsetOneByte_pushButton, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        noPeak_radioButton = new QRadioButton(groupBox_5);
        noPeak_radioButton->setObjectName(QStringLiteral("noPeak_radioButton"));

        horizontalLayout_6->addWidget(noPeak_radioButton);

        withPeak_radioButton = new QRadioButton(groupBox_5);
        withPeak_radioButton->setObjectName(QStringLiteral("withPeak_radioButton"));
        withPeak_radioButton->setChecked(true);

        horizontalLayout_6->addWidget(withPeak_radioButton);


        gridLayout_6->addLayout(horizontalLayout_6, 1, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_5, 2, 0, 1, 1);

        groupBox_6 = new QGroupBox(page);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout_9 = new QGridLayout(groupBox_6);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(-1, 2, -1, 5);
        groupBox_7 = new QGroupBox(groupBox_6);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_7 = new QGridLayout(groupBox_7);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(-1, 2, -1, 2);
        PeakSet_on_radioButton = new QRadioButton(groupBox_7);
        PeakSet_on_radioButton->setObjectName(QStringLiteral("PeakSet_on_radioButton"));
        PeakSet_on_radioButton->setChecked(true);

        gridLayout_7->addWidget(PeakSet_on_radioButton, 0, 0, 1, 1);

        PeakSet_off_radioButton = new QRadioButton(groupBox_7);
        PeakSet_off_radioButton->setObjectName(QStringLiteral("PeakSet_off_radioButton"));

        gridLayout_7->addWidget(PeakSet_off_radioButton, 0, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_7, 0, 0, 1, 1);

        groupBox_8 = new QGroupBox(groupBox_6);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        gridLayout_8 = new QGridLayout(groupBox_8);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(-1, 2, -1, 2);
        plotSet_on_radioButton = new QRadioButton(groupBox_8);
        plotSet_on_radioButton->setObjectName(QStringLiteral("plotSet_on_radioButton"));

        gridLayout_8->addWidget(plotSet_on_radioButton, 0, 0, 1, 1);

        plotSet_off_radioButton = new QRadioButton(groupBox_8);
        plotSet_off_radioButton->setObjectName(QStringLiteral("plotSet_off_radioButton"));
        plotSet_off_radioButton->setChecked(true);

        gridLayout_8->addWidget(plotSet_off_radioButton, 0, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_8, 1, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_6, 3, 0, 1, 1);

        groupBox_9 = new QGroupBox(page);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        gridLayout_10 = new QGridLayout(groupBox_9);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(-1, 3, -1, -1);
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_2 = new QLabel(groupBox_9);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        averageSample_lineEdit = new QLineEdit(groupBox_9);
        averageSample_lineEdit->setObjectName(QStringLiteral("averageSample_lineEdit"));
        averageSample_lineEdit->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, averageSample_lineEdit);

        label_4 = new QLabel(groupBox_9);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        Ratio_lineEdit = new QLineEdit(groupBox_9);
        Ratio_lineEdit->setObjectName(QStringLiteral("Ratio_lineEdit"));
        Ratio_lineEdit->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, Ratio_lineEdit);

        label_13 = new QLabel(groupBox_9);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_13);

        offset_lineEdit = new QLineEdit(groupBox_9);
        offset_lineEdit->setObjectName(QStringLiteral("offset_lineEdit"));
        offset_lineEdit->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, offset_lineEdit);


        gridLayout_10->addLayout(formLayout_2, 0, 0, 1, 1);


        gridLayout_11->addWidget(groupBox_9, 4, 0, 1, 1);

        gridLayout_11->setRowStretch(0, 6);
        gridLayout_11->setRowStretch(1, 5);
        gridLayout_11->setRowStretch(2, 2);
        gridLayout_11->setRowStretch(3, 5);
        gridLayout_11->setRowStretch(4, 3);
        toolBox->addItem(page, QString::fromUtf8("            \345\237\272\346\234\254\350\256\276\347\275\256"));
        splitter->addWidget(toolBox);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        HistoryData_label = new QLabel(groupBox);
        HistoryData_label->setObjectName(QStringLiteral("HistoryData_label"));
        HistoryData_label->setMinimumSize(QSize(70, 0));
        HistoryData_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(HistoryData_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        DPS_label = new QLabel(groupBox);
        DPS_label->setObjectName(QStringLiteral("DPS_label"));
        DPS_label->setMinimumSize(QSize(50, 0));
        DPS_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(DPS_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Transform_checkBox = new QCheckBox(groupBox);
        Transform_checkBox->setObjectName(QStringLiteral("Transform_checkBox"));
        Transform_checkBox->setChecked(true);

        horizontalLayout->addWidget(Transform_checkBox);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 5);
        horizontalLayout->setStretch(6, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        TimingSave_checkBox = new QCheckBox(groupBox);
        TimingSave_checkBox->setObjectName(QStringLiteral("TimingSave_checkBox"));

        horizontalLayout_3->addWidget(TimingSave_checkBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 7);

        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        savePath_lineEdit = new QLineEdit(groupBox);
        savePath_lineEdit->setObjectName(QStringLiteral("savePath_lineEdit"));

        horizontalLayout_7->addWidget(savePath_lineEdit);

        selectSavePathtoolButton = new QToolButton(groupBox);
        selectSavePathtoolButton->setObjectName(QStringLiteral("selectSavePathtoolButton"));

        horizontalLayout_7->addWidget(selectSavePathtoolButton);


        gridLayout->addLayout(horizontalLayout_7, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        save_pushButton = new QPushButton(groupBox);
        save_pushButton->setObjectName(QStringLiteral("save_pushButton"));

        horizontalLayout_4->addWidget(save_pushButton);

        timeInnterval_label = new QLabel(groupBox);
        timeInnterval_label->setObjectName(QStringLiteral("timeInnterval_label"));
        timeInnterval_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(timeInnterval_label);

        timeInnterval_lineEdit = new QLineEdit(groupBox);
        timeInnterval_lineEdit->setObjectName(QStringLiteral("timeInnterval_lineEdit"));
        timeInnterval_lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(timeInnterval_lineEdit);

        horizontalSpacer_6 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        clear_pushButton = new QPushButton(groupBox);
        clear_pushButton->setObjectName(QStringLiteral("clear_pushButton"));

        horizontalLayout_4->addWidget(clear_pushButton);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 5);

        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        ResultHistory_textEdit = new QPlainTextEdit(groupBox);
        ResultHistory_textEdit->setObjectName(QStringLiteral("ResultHistory_textEdit"));
        ResultHistory_textEdit->setStyleSheet(QString::fromUtf8("font: 9pt \"Source Code Pro\";\n"
"font: 9pt \"\351\273\221\344\275\223\";"));

        gridLayout->addWidget(ResultHistory_textEdit, 1, 0, 1, 1);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setStyleSheet(QLatin1String(".QGroupBox\n"
"{font: 10pt \"Times New Roman\";}"));
        gridLayout_12 = new QGridLayout(groupBox_2);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        TOF_radioButton = new QRadioButton(groupBox_2);
        TOF_radioButton->setObjectName(QStringLiteral("TOF_radioButton"));
        TOF_radioButton->setChecked(true);

        horizontalLayout_2->addWidget(TOF_radioButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        Histogram_radioButton = new QRadioButton(groupBox_2);
        Histogram_radioButton->setObjectName(QStringLiteral("Histogram_radioButton"));

        horizontalLayout_2->addWidget(Histogram_radioButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 3);

        gridLayout_12->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(groupBox_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        TOF_widget = new QCustomPlot(page_2);
        TOF_widget->setObjectName(QStringLiteral("TOF_widget"));

        gridLayout_2->addWidget(TOF_widget, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_13 = new QGridLayout(page_3);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        Histogram_widget = new QCustomPlot(page_3);
        Histogram_widget->setObjectName(QStringLiteral("Histogram_widget"));

        gridLayout_13->addWidget(Histogram_widget, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);

        gridLayout_12->addWidget(stackedWidget, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        savePicture_pushButton = new QPushButton(groupBox_2);
        savePicture_pushButton->setObjectName(QStringLiteral("savePicture_pushButton"));

        horizontalLayout_5->addWidget(savePicture_pushButton);

        horizontalSpacer_7 = new QSpacerItem(338, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 8);

        gridLayout_12->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        splitter->addWidget(groupBox_2);

        gridLayout_3->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1064, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "S3 \347\273\223\346\236\234\346\230\276\347\244\272\345\212\251\346\211\213", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", Q_NULLPTR));
        portScan_pushButton->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\346\243\200\346\265\213", Q_NULLPTR));
        openPort_pushButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\347\273\223\346\236\234\346\230\276\347\244\272:", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\350\267\235\347\246\273:(mm)", Q_NULLPTR));
        currentDistance_label->setText(QApplication::translate("MainWindow", "0.00", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\350\277\2211000\346\254\241\347\273\223\346\236\234\345\235\207\345\200\274\357\274\232", Q_NULLPTR));
        mean_label->setText(QApplication::translate("MainWindow", "0.00", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "\350\277\2211000\346\254\241\347\273\223\346\236\234\346\240\207\345\207\206\345\267\256\357\274\232", Q_NULLPTR));
        std_label->setText(QApplication::translate("MainWindow", "0.00", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\345\255\227\347\254\246\347\233\270\344\275\215:", Q_NULLPTR));
        offsetOneByte_pushButton->setText(QApplication::translate("MainWindow", "\345\201\217\347\247\273\344\270\200\345\255\227\350\212\202", Q_NULLPTR));
        noPeak_radioButton->setText(QApplication::translate("MainWindow", "\346\227\240peak\345\200\274", Q_NULLPTR));
        withPeak_radioButton->setText(QApplication::translate("MainWindow", "\346\234\211peak\345\200\274", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\346\230\276\347\244\272\350\256\276\347\275\256:", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Peak\345\200\274\346\230\276\347\244\272:", Q_NULLPTR));
        PeakSet_on_radioButton->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272", Q_NULLPTR));
        PeakSet_off_radioButton->setText(QApplication::translate("MainWindow", "\351\232\220\350\227\217", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "\347\224\273\345\233\276\345\212\237\350\203\275:", Q_NULLPTR));
        plotSet_on_radioButton->setText(QApplication::translate("MainWindow", "\345\274\200", Q_NULLPTR));
        plotSet_off_radioButton->setText(QApplication::translate("MainWindow", "\345\205\263", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "\346\240\241\345\207\206\345\217\202\346\225\260\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\235\207\345\237\237\357\274\232", Q_NULLPTR));
        averageSample_lineEdit->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\347\263\273\346\225\260\357\274\232", Q_NULLPTR));
        Ratio_lineEdit->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\345\201\217\347\247\273\357\274\232", Q_NULLPTR));
        offset_lineEdit->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "            \345\237\272\346\234\254\350\256\276\347\275\256", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\273\223\346\236\234\350\256\260\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\267\262\350\256\260\345\275\225\346\225\260\346\215\256:", Q_NULLPTR));
        HistoryData_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "DPS:", Q_NULLPTR));
        DPS_label->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        Transform_checkBox->setText(QApplication::translate("MainWindow", "\350\275\254\346\215\242", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266\350\267\257\345\276\204", Q_NULLPTR));
        TimingSave_checkBox->setText(QApplication::translate("MainWindow", "\345\256\232\346\227\266\344\277\235\345\255\230", Q_NULLPTR));
        selectSavePathtoolButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        save_pushButton->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        timeInnterval_label->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\351\227\264\351\232\224(S):", Q_NULLPTR));
        timeInnterval_lineEdit->setText(QApplication::translate("MainWindow", "60", Q_NULLPTR));
        clear_pushButton->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\347\224\273\345\233\276", Q_NULLPTR));
        TOF_radioButton->setText(QApplication::translate("MainWindow", "TOF\345\233\276", Q_NULLPTR));
        Histogram_radioButton->setText(QApplication::translate("MainWindow", "\347\233\264\346\226\271\345\233\276", Q_NULLPTR));
        savePicture_pushButton->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
