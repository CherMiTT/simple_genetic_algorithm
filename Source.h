/**
* \file
* \brief Заголовочный файл с объявлением функций для основного файла программы
* \author CherMi
* \date	28.03.N21
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
	friend bool operator==(const Osob& left, const Osob& right);

	singleOsob x, y;
};

double f(double x, double y);
singleOsob doubleToOsob(double A, double B, double eps, double number);
double osobToDouble(double A, double B, double eps, singleOsob osob);
void printPopulation(std::array<Osob, N> &p, const double& A, const double& B, const double& C, const double& D, const double& eps);
void printVOsobs(std::vector<Osob> &v, const double& A, const double& B, const double& C, const double& D, const double& eps);
void mutatePopulation(std::array<Osob, N> &p);
void breedNewGeneration(std::array<Osob, N> &p);
void shuffleBestOsobsIntoPopulation(std::array<Osob, N>& p, std::vector<Osob>& v);
void saveBestOsobs(std::array<Osob, N>& p, std::vector<Osob>& v);
bool compare(Osob& o1, Osob& o2);