/****************************************************************************
** Meta object code from reading C++ file 'dlgserach.h'
**
** Created: Fri Mar 23 16:34:10 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Dialog/dlgserach.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgserach.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDlgSerach[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   43,   11,   11, 0x08,
      93,   88,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CDlgSerach[] = {
    "CDlgSerach\0\0strCardID\0PositionRow(QString)\0"
    "row,\0on_tabResult_cellDoubleClicked(int,int)\0"
    "link\0on_lblClose_linkActivated(QString)\0"
    "on_btnClose_clicked()\0"
};

const QMetaObject CDlgSerach::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CDlgSerach,
      qt_meta_data_CDlgSerach, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDlgSerach::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDlgSerach::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDlgSerach::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDlgSerach))
        return static_cast<void*>(const_cast< CDlgSerach*>(this));
    return QDialog::qt_metacast(_clname);
}

int CDlgSerach::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: PositionRow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_tabResult_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: on_lblClose_linkActivated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: on_btnClose_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CDlgSerach::PositionRow(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE