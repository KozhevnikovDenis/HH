#pragma once

// Сформированные компьютером классы-оболочки IDispatch, созданные при помощи Microsoft Visual C++

// Примечание. Не изменяйте содержимое этого файла. При повторном создании этого класса
// в Microsoft Visual C++ изменения будут перезаписаны.

/////////////////////////////////////////////////////////////////////////////

#include "afxwin.h"

class COCX : public CWnd
{
protected:
	DECLARE_DYNCREATE(COCX)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x8e27c92b,0x1264,0x101c,{0x8a,0x2f,0x04,0x02,0x24,0x00,0x9c,0x02} };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = nullptr)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID);
	}

	BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
		UINT nID, CFile* pPersist = nullptr, BOOL bStorage = FALSE,
		BSTR bstrLicKey = nullptr)
	{
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
			pPersist, bStorage, bstrLicKey);
	}

	// Атрибуты
public:


	// Операции
public:
	// ICalendar

	// Функции
	//

	unsigned long get_BackColor()
	{
		unsigned long result;
		InvokeHelper(0xfffffe0b, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, nullptr);
		return result;
	}
	void put_BackColor(unsigned long newValue)
	{
		//static BYTE parms[] = VT_UI4;
		//InvokeHelper(0xfffffe0b, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	short get_Day()
	{
		short result;
		InvokeHelper(0x11, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, nullptr);
		return result;
	}
	void put_Day(short newValue)
	{
		static BYTE parms[] = VTS_I2;
		InvokeHelper(0x11, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	LPDISPATCH get_DayFont()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void put_DayFont(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	unsigned long get_DayFontColor()
	{
		unsigned long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, nullptr);
		return result;
	}
	void put_DayFontColor(unsigned long newValue)
	{
		//static BYTE parms[] = VT_UI4;
		//InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	short get_DayLength()
	{
		short result;
		InvokeHelper(0x12, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, nullptr);
		return result;
	}
	void put_DayLength(short newValue)
	{
		static BYTE parms[] = VTS_I2;
		InvokeHelper(0x12, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	short get_FirstDay()
	{
		short result;
		InvokeHelper(0x13, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, nullptr);
		return result;
	}
	void put_FirstDay(short newValue)
	{
		static BYTE parms[] = VTS_I2;
		InvokeHelper(0x13, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	long get_GridCellEffect()
	{
		long result;
		InvokeHelper(0x14, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, nullptr);
		return result;
	}
	void put_GridCellEffect(long newValue)
	{
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x14, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	LPDISPATCH get_GridFont()
	{
		LPDISPATCH result;
		InvokeHelper(0x3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void put_GridFont(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	unsigned long get_GridFontColor()
	{
		unsigned long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, nullptr);
		return result;
	}
	void put_GridFontColor(unsigned long newValue)
	{
		//static BYTE parms[] = VT_UI4;
		//InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	unsigned long get_GridLinesColor()
	{
		unsigned long result;
		InvokeHelper(0xd, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, nullptr);
		return result;
	}
	void put_GridLinesColor(unsigned long newValue)
	{
		//static BYTE parms[] = VT_UI4;
		//InvokeHelper(0xd, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	short get_Month()
	{
		short result;
		InvokeHelper(0x10, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, nullptr);
		return result;
	}
	void put_Month(short newValue)
	{
		static BYTE parms[] = VTS_I2;
		InvokeHelper(0x10, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	short get_MonthLength()
	{
		short result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, nullptr);
		return result;
	}
	void put_MonthLength(short newValue)
	{
		static BYTE parms[] = VTS_I2;
		InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_ShowDateSelectors()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_ShowDateSelectors(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_ShowDays()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_ShowDays(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_ShowHorizontalGrid()
	{
		BOOL result;
		InvokeHelper(0x7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_ShowHorizontalGrid(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x7, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_ShowTitle()
	{
		BOOL result;
		InvokeHelper(0x8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_ShowTitle(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x8, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	BOOL get_ShowVerticalGrid()
	{
		BOOL result;
		InvokeHelper(0x9, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_ShowVerticalGrid(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0x9, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	LPDISPATCH get_TitleFont()
	{
		LPDISPATCH result;
		InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, nullptr);
		return result;
	}
	void put_TitleFont(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	unsigned long get_TitleFontColor()
	{
		unsigned long result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, nullptr);
		return result;
	}
	void put_TitleFontColor(unsigned long newValue)
	{
		//static BYTE parms[] = VT_UI4;
		//InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	VARIANT get_Value()
	{
		VARIANT result;
		InvokeHelper(0xc, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, nullptr);
		return result;
	}
	void put_Value(VARIANT newValue)
	{
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0xc, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, &newValue);
	}
	VARIANT get__Value()
	{
		VARIANT result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, nullptr);
		return result;
	}
	void put__Value(VARIANT newValue)
	{
		static BYTE parms[] = VTS_VARIANT;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, &newValue);
	}
	BOOL get_ValueIsNull()
	{
		BOOL result;
		InvokeHelper(0xe, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, nullptr);
		return result;
	}
	void put_ValueIsNull(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL;
		InvokeHelper(0xe, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	short get_Year()
	{
		short result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_I2, (void*)&result, nullptr);
		return result;
	}
	void put_Year(short newValue)
	{
		static BYTE parms[] = VTS_I2;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, nullptr, parms, newValue);
	}
	void NextDay()
	{
		InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void NextMonth()
	{
		InvokeHelper(0x17, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void NextWeek()
	{
		InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void NextYear()
	{
		InvokeHelper(0x19, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void PreviousDay()
	{
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void PreviousMonth()
	{
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void PreviousWeek()
	{
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void PreviousYear()
	{
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void Refresh()
	{
		InvokeHelper(0xfffffdda, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void Today()
	{
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void AboutBox()
	{
		InvokeHelper(0xfffffdd8, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void putref_DayFont(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUTREF, VT_EMPTY, nullptr, parms, newValue);
	}
	void putref_GridFont(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0x3, DISPATCH_PROPERTYPUTREF, VT_EMPTY, nullptr, parms, newValue);
	}
	void putref_TitleFont(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH;
		InvokeHelper(0xa, DISPATCH_PROPERTYPUTREF, VT_EMPTY, nullptr, parms, newValue);
	}

	// Свойства
	//

	// DCalendarEvents

	// Функции
	//

	void Click()
	{
		InvokeHelper(0xfffffda8, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void DblClick()
	{
		InvokeHelper(0xfffffda7, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void KeyDown(short* KeyCode, short Shift)
	{
		//static BYTE parms[] = SHORT * VTS_I2 ;
		//InvokeHelper(0xfffffda6, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, KeyCode, Shift);
	}
	void KeyPress(short* KeyAscii)
	{
		//static BYTE parms[] = SHORT * ;
		//InvokeHelper(0xfffffda5, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, KeyAscii);
	}
	void KeyUp(short* KeyCode, short Shift)
	{
		//static BYTE parms[] = SHORT * VTS_I2 ;
		//InvokeHelper(0xfffffda4, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, KeyCode, Shift);
	}
	void BeforeUpdate(short* Cancel)
	{
		//static BYTE parms[] = SHORT * ;
		//InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, nullptr, parms, Cancel);
	}
	void AfterUpdate()
	{
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void NewMonth()
	{
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}
	void NewYear()
	{
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, nullptr, nullptr);
	}

	// Свойства
	//



};