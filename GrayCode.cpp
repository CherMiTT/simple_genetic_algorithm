/**
* \file
* \brief Файл с реализацией методов для преобразования из позиционного двоичного кода в код Грея и наоборот.
* \author CherMi
* \date	28.03.2021
* \version 1.0
*/


#include "GrayCode.h"

OSOB toGrayCode(const OSOB &PosCode)
{
	return PosCode ^ (PosCode >> 1);
}

OSOB toPosCode(const OSOB &GrayCode)
{
    unsigned long n = 0;
    unsigned long g = GrayCode.to_ulong();
    for (; g; g >>= 1)
        n ^= g;
    return OSOB(n);
}