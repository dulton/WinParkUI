/****************************************************************************
** Meta object code from reading C++ file 'dbmaintenance.h'
**
** Created: Fri Apr 27 18:44:50 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Header/dbmaintenance.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbmaintenance.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDBMaintenance[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      51,   15,   15,   15, 0x08,
      73,   15,   15,   15, 0x08,
      96,   15,   15,   15, 0x08,
     121,   15,   15,   15, 0x08,
     142,   15,   15,   15, 0x08,
     169,   15,   15,   15, 0x08,
     197,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CDBMaintenance[] = {
    "CDBMaintenance\0\0on_lblClose_linkActivated(QString)\0"
    "on_btnClose_clicked()\0on_btnBackup_clicked()\0"
    "on_btnRecovery_clicked()\0on_btnSave_clicked()\0"
    "on_btnBackupPath_clicked()\0"
    "on_btnRecoveyPath_clicked()\0ClearData()\0"
};

const QMetaObject CDBMaintenance::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_CDBMaintenance,
      qt_meta_data_CDBMaintenance, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDBMaintenance::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDBMaintenance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDBMaintenance::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDBMaintenance))
        return static_cast<void*>(const_cast< CDBMaintenance*>(this));
    return QFrame::qt_metacast(_clname);
}

int CDBMaintenance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_lblClose_linkActivated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: on_btnClose_clicked(); break;
        case 2: on_btnBackup_clicked(); break;
        case 3: on_btnRecovery_clicked(); break;
        case 4: on_btnSave_clicked(); break;
        case 5: on_btnBackupPath_clicked(); break;
        case 6: on_btnRecoveyPath_clicked(); break;
        case 7: ClearData(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE