/****************************************************************************
** Meta object code from reading C++ file 'printmonthlyreport.h'
**
** Created: Tue Apr 10 17:05:39 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Header/printmonthlyreport.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printmonthlyreport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CPrintMonthlyReport[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      46,   21,   20,   20, 0x05,
      82,   73,   20,   20, 0x05,
     126,  108,   20,   20, 0x05,
     160,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     183,   20,   20,   20, 0x08,
     202,   20,   20,   20, 0x08,
     221,   20,   20,   20, 0x08,
     236,   20,   20,   20, 0x08,
     254,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CPrintMonthlyReport[] = {
    "CPrintMonthlyReport\0\0strValue,nChannel,nIndex\0"
    "SendValue(QString,int,int)\0nChannel\0"
    "ManualRecogonization(int)\0nChannel,strPlate\0"
    "ManualRecogonization(int,QString)\0"
    "ClearMonitorPlate(int)\0on_btn96_clicked()\0"
    "on_btn99_clicked()\0OnBtnClicked()\0"
    "OnBtnResClicked()\0on_btnClear_clicked()\0"
};

const QMetaObject CPrintMonthlyReport::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_CPrintMonthlyReport,
      qt_meta_data_CPrintMonthlyReport, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CPrintMonthlyReport::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CPrintMonthlyReport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CPrintMonthlyReport::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CPrintMonthlyReport))
        return static_cast<void*>(const_cast< CPrintMonthlyReport*>(this));
    return QFrame::qt_metacast(_clname);
}

int CPrintMonthlyReport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SendValue((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: ManualRecogonization((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: ManualRecogonization((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: ClearMonitorPlate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_btn96_clicked(); break;
        case 5: on_btn99_clicked(); break;
        case 6: OnBtnClicked(); break;
        case 7: OnBtnResClicked(); break;
        case 8: on_btnClear_clicked(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CPrintMonthlyReport::SendValue(QString _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CPrintMonthlyReport::ManualRecogonization(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CPrintMonthlyReport::ManualRecogonization(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CPrintMonthlyReport::ClearMonitorPlate(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE