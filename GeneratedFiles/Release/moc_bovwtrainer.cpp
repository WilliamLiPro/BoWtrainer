/****************************************************************************
** Meta object code from reading C++ file 'bovwtrainer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bovwtrainer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bovwtrainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BoVWTrainer_t {
    QByteArrayData data[16];
    char stringdata[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BoVWTrainer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BoVWTrainer_t qt_meta_stringdata_BoVWTrainer = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 14),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 18),
QT_MOC_LITERAL(4, 47, 16),
QT_MOC_LITERAL(5, 64, 9),
QT_MOC_LITERAL(6, 74, 17),
QT_MOC_LITERAL(7, 92, 11),
QT_MOC_LITERAL(8, 104, 13),
QT_MOC_LITERAL(9, 118, 12),
QT_MOC_LITERAL(10, 131, 13),
QT_MOC_LITERAL(11, 145, 15),
QT_MOC_LITERAL(12, 161, 12),
QT_MOC_LITERAL(13, 174, 14),
QT_MOC_LITERAL(14, 189, 13),
QT_MOC_LITERAL(15, 203, 8)
    },
    "BoVWTrainer\0setFeatureType\0\0"
    "setBoVWFeatureType\0updateCameraInfo\0"
    "setCamera\0selectDatasetPath\0runSampling\0"
    "pauseSampling\0stopSampling\0setBoVWlevels\0"
    "setBoVWbranches\0runBoVWtrain\0"
    "pauseBoVWtrain\0stopBoVWtrain\0openHelp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BoVWTrainer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,

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
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BoVWTrainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BoVWTrainer *_t = static_cast<BoVWTrainer *>(_o);
        switch (_id) {
        case 0: _t->setFeatureType(); break;
        case 1: _t->setBoVWFeatureType(); break;
        case 2: _t->updateCameraInfo(); break;
        case 3: _t->setCamera(); break;
        case 4: _t->selectDatasetPath(); break;
        case 5: _t->runSampling(); break;
        case 6: _t->pauseSampling(); break;
        case 7: _t->stopSampling(); break;
        case 8: _t->setBoVWlevels(); break;
        case 9: _t->setBoVWbranches(); break;
        case 10: _t->runBoVWtrain(); break;
        case 11: _t->pauseBoVWtrain(); break;
        case 12: _t->stopBoVWtrain(); break;
        case 13: _t->openHelp(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject BoVWTrainer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BoVWTrainer.data,
      qt_meta_data_BoVWTrainer,  qt_static_metacall, 0, 0}
};


const QMetaObject *BoVWTrainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BoVWTrainer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BoVWTrainer.stringdata))
        return static_cast<void*>(const_cast< BoVWTrainer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BoVWTrainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
