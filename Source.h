/**
* \file
* \brief Заголовочный файл с объявлением функций для основного файла программы
* \author CherMi
* \date	28.03.2021
* \version 1.0
*/

#pragma once

#include <iostream>
#include "GrayCode.h"

/// <summary>
/// Функция, заданная в задании: \f$ f(x, y) = x^2 + 100 * (y - 1)^2 - 1 \f$
/// </summary>
/// <param name="x">Параметр x</param>
/// <param name="y">Параметр y</param>
/// <returns>Значение функции f(x, y)</returns>
double f(double x, double y);

/** \brief Ставит в соответсвие десятичному числу из диапазона [A, B] двоичное число
* \param A, B - границы отрезка [A, B]
* \param eps - точность, с которой рассматривается отрезок
* \param number - десятичное число, которому в соответсвие ставим ПДК 
* \return Соответсвующую особь в позиционном двоичном коде
*/
OSOB doubleToOsob(double A, double B, double eps, double number);

/** \brief Ставит в соответсвие особи в позиционном двоичном коде десятичное число из диапазона [A, B]
* \param A, B - границы отрезка [A, B]
* \param eps - точность, с которой рассматривается отрезок
* \param osob - особь в ПДК
* \return Соответсвующее десятичное число
*/
double osobToDouble(double A, double B, double eps, OSOB osob);