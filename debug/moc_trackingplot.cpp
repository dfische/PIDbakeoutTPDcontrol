/****************************************************************************
** Meta object code from reading C++ file 'trackingplot.h'
**
** Created: Thu 29. Nov 12:04:47 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../trackingplot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trackingplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_trackingPlot[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      26,   13,   13,   13, 0x08,
      44,   37,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_trackingPlot[] = {
    "trackingPlot\0\0resetPlot()\0savePlot()\0"
    "yValue\0addValue(double)\0"
};

void trackingPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        trackingPlot *_t = static_cast<trackingPlot *>(_o);
        switch (_id) {
        case 0: _t->resetPlot(); break;
        case 1: _t->savePlot(); break;
        case 2: _t->addValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData trackingPlot::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject trackingPlot::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_trackingPlot,
      qt_meta_data_trackingPlot, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &trackingPlot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *trackingPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *trackingPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_trackingPlot))
        return static_cast<void*>(const_cast< trackingPlot*>(this));
    return QwtPlot::qt_metacast(_clname);
}

int trackingPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE