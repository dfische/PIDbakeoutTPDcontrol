/****************************************************************************
** Meta object code from reading C++ file 'combivac.h'
**
** Created: Thu 29. Nov 11:56:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../combivac.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'combivac.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_pressureRequest[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_pressureRequest[] = {
    "pressureRequest\0"
};

void pressureRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData pressureRequest::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject pressureRequest::staticMetaObject = {
    { &serialRequest::staticMetaObject, qt_meta_stringdata_pressureRequest,
      qt_meta_data_pressureRequest, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &pressureRequest::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *pressureRequest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *pressureRequest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pressureRequest))
        return static_cast<void*>(const_cast< pressureRequest*>(this));
    return serialRequest::qt_metacast(_clname);
}

int pressureRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = serialRequest::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_combivac[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_combivac[] = {
    "combivac\0"
};

void combivac::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData combivac::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject combivac::staticMetaObject = {
    { &serial::staticMetaObject, qt_meta_stringdata_combivac,
      qt_meta_data_combivac, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &combivac::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *combivac::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *combivac::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_combivac))
        return static_cast<void*>(const_cast< combivac*>(this));
    return serial::qt_metacast(_clname);
}

int combivac::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = serial::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
