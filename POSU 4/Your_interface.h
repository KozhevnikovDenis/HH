#pragma once
#include <objbase.h>

// {0078760B-C4CE-4DEC-AFF6-A5476CB94F31}
static const GUID IID_ICalc =
{ 0x78760b, 0xc4ce, 0x4dec, { 0xaf, 0xf6, 0xa5, 0x47, 0x6c, 0xb9, 0x4f, 0x31 } };


interface ICalc : public IUnknown
{
	// пользовательская функция нашего интерфейса
	STDMETHOD_(int, Sum) (int first, int second) = 0;
};