/****************************************************************************
** Meta object code from reading C++ file 'dialogcombivac.h'
**
** Created: Tue 27. Nov 14:06:49 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialogcombivac.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogcombivac.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dialogCombivac[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      54,   15,   15,   15, 0x08,
      91,   15,   15,   15, 0x08,
     114,   15,   15,   15, 0x08,
     137,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dialogCombivac[] = {
    "dialogCombivac\0\0on_startPressureMeasurement_clicked()\0"
    "on_stopPressureMeasurement_clicked()\0"
    "pressureCombi1(double)\0pressureCombi2(double)\0"
    "pressureIonGauge(double)\0"
};

void dialogCombivac::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        dialogCombivac *_t = static_cast<dialogCombivac *>(_o);
        switch (_id) {
        case 0: _t->on_startPressureMeasurement_clicked(); break;
        case 1: _t->on_stopPressureMeasurement_clicked(); break;
        case 2: _t->pressureCombi1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->pressureCombi2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->pressureIonGauge((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dialogCombivac::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dialogCombivac::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dialogCombivac,
      qt_meta_data_dialogCombivac, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dialogCombivac::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dialogCombivac::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dialogCombivac::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dialogCombivac))
        return static_cast<void*>(const_cast< dialogCombivac*>(this));
    return QWidget::qt_metacast(_clname);
}

int dialogCombivac::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
