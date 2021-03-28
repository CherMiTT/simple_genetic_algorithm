/**
* \file
* \brief Основной файл программы
* \author CherMi
* \date	28.03.2021
* \version 1.0
*/


#include "Source.h"

using namespace std;

double f(double x, double y)
{
	return x * x + 100 * pow((y - 1), 2) - 1;
}

OSOB doubleToOsob(double A, double B, double eps, double number)
{
	number = number / eps + fabs(A) / eps;
	return OSOB(number);
}

double osobToDouble(double A, double B, double eps, OSOB osob)
{
	double number = (double) osob.to_ulong();
	return (number - fabs(A / eps)) * eps;
}

int main()
{
	double a = -10, b = 10; /// \param a, b Границы для переменной x
	double c = -10, d = 10; /// \param c, d Границы для переменной y
	double eps = 0.0001; /// \param eps Заданная точность

	double discr_count_x = (b - a) / eps;
	double discr_count_y = (d - c) / eps;
	return 0;
}


