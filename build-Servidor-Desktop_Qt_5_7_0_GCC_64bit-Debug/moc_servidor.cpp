/****************************************************************************
** Meta object code from reading C++ file 'servidor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Servidor/servidor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'servidor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_servidor_t {
    QByteArrayData data[5];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_servidor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_servidor_t qt_meta_stringdata_servidor = {
    {
QT_MOC_LITERAL(0, 0, 8), // "servidor"
QT_MOC_LITERAL(1, 9, 14), // "conexion_nueva"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 18), // "leer_socketcliente"
QT_MOC_LITERAL(4, 44, 18) // "on_client1_clicked"

    },
    "servidor\0conexion_nueva\0\0leer_socketcliente\0"
    "on_client1_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_servidor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void servidor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        servidor *_t = static_cast<servidor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->conexion_nueva(); break;
        case 1: _t->leer_socketcliente(); break;
        case 2: _t->on_client1_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject servidor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_servidor.data,
      qt_meta_data_servidor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *servidor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *servidor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_servidor.stringdata0))
        return static_cast<void*>(const_cast< servidor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int servidor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
