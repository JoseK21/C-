/****************************************************************************
** Meta object code from reading C++ file 'cliente.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Cliente/cliente.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cliente.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Cliente_t {
    QByteArrayData data[12];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cliente_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cliente_t qt_meta_stringdata_Cliente = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Cliente"
QT_MOC_LITERAL(1, 8, 19), // "leer_socketservidor"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 29), // "on_Escribiralservidor_clicked"
QT_MOC_LITERAL(4, 59, 2), // "da"
QT_MOC_LITERAL(5, 62, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(6, 86, 27), // "on_actionNew_File_triggered"
QT_MOC_LITERAL(7, 114, 28), // "on_actionOpen_File_triggered"
QT_MOC_LITERAL(8, 143, 14), // "on_run_clicked"
QT_MOC_LITERAL(9, 158, 15), // "on_stop_clicked"
QT_MOC_LITERAL(10, 174, 16), // "on_go_on_clicked"
QT_MOC_LITERAL(11, 191, 16) // "on_clear_clicked"

    },
    "Cliente\0leer_socketservidor\0\0"
    "on_Escribiralservidor_clicked\0da\0"
    "on_actionExit_triggered\0"
    "on_actionNew_File_triggered\0"
    "on_actionOpen_File_triggered\0"
    "on_run_clicked\0on_stop_clicked\0"
    "on_go_on_clicked\0on_clear_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cliente[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    1,   60,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Cliente::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cliente *_t = static_cast<Cliente *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->leer_socketservidor(); break;
        case 1: _t->on_Escribiralservidor_clicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_actionExit_triggered(); break;
        case 3: _t->on_actionNew_File_triggered(); break;
        case 4: _t->on_actionOpen_File_triggered(); break;
        case 5: _t->on_run_clicked(); break;
        case 6: _t->on_stop_clicked(); break;
        case 7: _t->on_go_on_clicked(); break;
        case 8: _t->on_clear_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Cliente::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Cliente.data,
      qt_meta_data_Cliente,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Cliente::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cliente::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Cliente.stringdata0))
        return static_cast<void*>(const_cast< Cliente*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Cliente::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
