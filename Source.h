/**
* \file
* \brief Заголовочный файл с объявлением функций для основного файла программы
* \author CherMi
* \date	28.03.2021
* \version 1.0
*/

#pragma once

#include <iostream>
#include <array>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>
#include "GrayCode.h"

/** \brief Класс особи для задачи. Содержит две переменные типа singleOsob, которые вместе и образуют особь.
*/
class Osob
{
public:
	Osob();
	Osob(singleOsob x, singleOsob y);
	~Osob();
	std::string toString();
	std::string toString(singleOsob x, singleOsob y);

	singleOsob x, y;
};

double f(double x, double y);
singleOsob doubleToOsob(double A, double B, double eps, double number);
double osobToDouble(double A, double B, double eps, singleOsob osob);
void printPopulation(std::array<Osob, 20> p, const double& A, const double& B, const double& C, const double& D, const double& eps);
void createNewGeneration(std::array<Osob, 20> &p);