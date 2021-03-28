/**
* \file
* \brief Заголовочный файл с описанием типа и методов для преобразования из позиционного двоичного кода в код Грея и наоборот.
* \author CherMi
* \date	28.03.2021
* \version 1.0
*/

#pragma once

#include <bitset>

/// Тип особи размером в 16 генов по 1 байту
using OSOB = std::bitset<16>;

/**
* \brief Преобразует особь из ПДК в код Грея
* \param PosCode Особь в позиционном коде
* \return Соответсвующая особь в коде Грея
*/
OSOB toGrayCode(const OSOB& PosCode);

/**
* \brief Преобразует особь из кода Грея в ПДК
* \param GrayCode Особь в коде Грея
* \return Соответсвующая особь в ПДК
*/
OSOB toPosCode(const OSOB& GrayCode);