/**
* \file
* \brief Заголовочный файл с описанием типа и методов для преобразования из позиционного двоичного кода в код Грея и наоборот.
* \author CherMi
* \date	28.03.N21
* \version 1.0
*/

#pragma once

#include <bitset>

const size_t M = 18; ///Количество генов на одну переменную
const size_t N = 20; ///Размер популяции

/// Тип особи для одной переменной размером в M генов по 1 байту
using singleOsob = std::bitset<M>;

singleOsob toGrayCode(const singleOsob& PosCode);
singleOsob toPosCode(const singleOsob& GrayCode);