/**
* \file
* \brief Файл с реализацией методов для преобразования из позиционного двоичного кода в код Грея и наоборот.
* \author CherMi
* \date	28.03.N21
* \version 1.0
*/


#include "GrayCode.h"

/**
* \brief Преобразует особь из ПДК в код Грея
* \param PosCode Особь в позиционном коде
* \return Соответсвующая особь в коде Грея
*/
singleOsob toGrayCode(const singleOsob &PosCode)
{
	return PosCode ^ (PosCode >> 1);
}

/**
* \brief Преобразует особь из ПДК в код Грея
* \param PosCode Особь в позиционном коде
* \return Соответсвующая особь в коде Грея
*/
singleOsob toPosCode(const singleOsob &GrayCode)
{
    unsigned long n = 0;
    unsigned long g = GrayCode.to_ulong();
    for (; g; g >>= 1)
        n ^= g;
    return singleOsob(n);
}