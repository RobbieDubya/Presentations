/****************************************************************************
** Meta object code from reading C++ file 'CameraInvoker.hpp'
**
** Created: Tue Dec 18 11:02:58 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/CameraInvoker.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CameraInvoker.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CameraInvoker[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   15,   14,   14, 0x0a,
      68,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CameraInvoker[] = {
    "CameraInvoker\0\0message\0"
    "onChildCardDone(bb::system::CardDoneMessage)\0"
    "onInvokeButtonClicked()\0"
};

void CameraInvoker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CameraInvoker *_t = static_cast<CameraInvoker *>(_o);
        switch (_id) {
        case 0: _t->onChildCardDone((*reinterpret_cast< const bb::system::CardDoneMessage(*)>(_a[1]))); break;
        case 1: _t->onInvokeButtonClicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CameraInvoker::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CameraInvoker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CameraInvoker,
      qt_meta_data_CameraInvoker, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CameraInvoker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CameraInvoker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CameraInvoker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CameraInvoker))
        return static_cast<void*>(const_cast< CameraInvoker*>(this));
    return QObject::qt_metacast(_clname);
}

int CameraInvoker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
