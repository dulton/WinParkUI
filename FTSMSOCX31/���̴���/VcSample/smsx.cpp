// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "smsx.h"

/////////////////////////////////////////////////////////////////////////////
// CSMSX

IMPLEMENT_DYNCREATE(CSMSX, CWnd)

/////////////////////////////////////////////////////////////////////////////
// CSMSX properties

/////////////////////////////////////////////////////////////////////////////
// CSMSX operations

long CSMSX::Init()
{
	long result;
	InvokeHelper(0x21, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

long CSMSX::ConnectModem(LPCTSTR PortName, long BaudRate, LPCTSTR AccessCode)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR VTS_I4 VTS_BSTR;
	InvokeHelper(0x22, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		PortName, BaudRate, AccessCode);
	return result;
}

void CSMSX::DisconnectModem()
{
	InvokeHelper(0x23, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CSMSX::SetSend(BOOL SendFlag)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x24, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 SendFlag);
}

void CSMSX::SetRecv(BOOL RecvFlag)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x25, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 RecvFlag);
}

long CSMSX::SendMsg(LPCTSTR DestNum, LPCTSTR Content, long MsgIndex)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR VTS_I4;
	InvokeHelper(0x26, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		DestNum, Content, MsgIndex);
	return result;
}

long CSMSX::SendListCount()
{
	long result;
	InvokeHelper(0x27, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL CSMSX::ModemConnected()
{
	BOOL result;
	InvokeHelper(0x28, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

long CSMSX::RecvListCount()
{
	long result;
	InvokeHelper(0x12, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
	return result;
}

void CSMSX::RecvMsg(BSTR* PhoneNum, BSTR* Content, long* Year, long* Month, long* Day, long* Hour, long* Minute, long* Second)
{
	static BYTE parms[] =
		VTS_PBSTR VTS_PBSTR VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4;
	InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 PhoneNum, Content, Year, Month, Day, Hour, Minute, Second);
}
