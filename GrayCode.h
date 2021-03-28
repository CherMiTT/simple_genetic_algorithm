/**
* \file
* \brief Заголовочный файл с описанием типа и методов для преобразования из позиционного двоичного кода в код Грея и наоборот.
* \author CherMi
* \date	28.03.2021
* \version 1.0
*/

#pragma once

#include <bitset>

/// Тип особи для одной переменной размером в 18 генов по 1 байту
using singleOsob = std::bitset<18>;

singleOsob toGrayCode(const singleOsob& PosCode);
singleOsob toPosCode(const singleOsob& GrayCode);