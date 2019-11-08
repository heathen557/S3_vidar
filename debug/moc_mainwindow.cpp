/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[473];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 26), // "on_save_pushButton_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 33), // "on_plotSet_on_radioButton_cli..."
QT_MOC_LITERAL(4, 73, 34), // "on_plotSet_off_radioButton_cl..."
QT_MOC_LITERAL(5, 108, 30), // "on_openPort_pushButton_clicked"
QT_MOC_LITERAL(6, 139, 13), // "portOnSetting"
QT_MOC_LITERAL(7, 153, 14), // "portOffSetting"
QT_MOC_LITERAL(8, 168, 39), // "on_averageSample_lineEdit_ret..."
QT_MOC_LITERAL(9, 208, 31), // "on_Ratio_lineEdit_returnPressed"
QT_MOC_LITERAL(10, 240, 32), // "on_offset_lineEdit_returnPressed"
QT_MOC_LITERAL(11, 273, 29), // "on_Transform_checkBox_clicked"
QT_MOC_LITERAL(12, 303, 33), // "on_PeakSet_on_radioButton_cli..."
QT_MOC_LITERAL(13, 337, 34), // "on_PeakSet_off_radioButton_cl..."
QT_MOC_LITERAL(14, 372, 15), // "dealedData_slot"
QT_MOC_LITERAL(15, 388, 13), // "vector<float>"
QT_MOC_LITERAL(16, 402, 13), // "showTimerSlot"
QT_MOC_LITERAL(17, 416, 10), // "beginTimer"
QT_MOC_LITERAL(18, 427, 9), // "stopTimer"
QT_MOC_LITERAL(19, 437, 35) // "on_selectSavePathtoolButton_c..."

    },
    "MainWindow\0on_save_pushButton_clicked\0"
    "\0on_plotSet_on_radioButton_clicked\0"
    "on_plotSet_off_radioButton_clicked\0"
    "on_openPort_pushButton_clicked\0"
    "portOnSetting\0portOffSetting\0"
    "on_averageSample_lineEdit_returnPressed\0"
    "on_Ratio_lineEdit_returnPressed\0"
    "on_offset_lineEdit_returnPressed\0"
    "on_Transform_checkBox_clicked\0"
    "on_PeakSet_on_radioButton_clicked\0"
    "on_PeakSet_off_radioButton_clicked\0"
    "dealedData_slot\0vector<float>\0"
    "showTimerSlot\0beginTimer\0stopTimer\0"
    "on_selectSavePathtoolButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    3,  111,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15, 0x80000000 | 15,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_save_pushButton_clicked(); break;
        case 1: _t->on_plotSet_on_radioButton_clicked(); break;
        case 2: _t->on_plotSet_off_radioButton_clicked(); break;
        case 3: _t->on_openPort_pushButton_clicked(); break;
        case 4: _t->portOnSetting(); break;
        case 5: _t->portOffSetting(); break;
        case 6: _t->on_averageSample_lineEdit_returnPressed(); break;
        case 7: _t->on_Ratio_lineEdit_returnPressed(); break;
        case 8: _t->on_offset_lineEdit_returnPressed(); break;
        case 9: _t->on_Transform_checkBox_clicked(); break;
        case 10: _t->on_PeakSet_on_radioButton_clicked(); break;
        case 11: _t->on_PeakSet_off_radioButton_clicked(); break;
        case 12: _t->dealedData_slot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< vector<float>(*)>(_a[2])),(*reinterpret_cast< vector<float>(*)>(_a[3]))); break;
        case 13: _t->showTimerSlot(); break;
        case 14: _t->beginTimer(); break;
        case 15: _t->stopTimer(); break;
        case 16: _t->on_selectSavePathtoolButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
