/**
* \file
* \brief Основной файл программы
* \author CherMi
* \date	28.03.2021
* \version 1.0
*/


#include "Source.h"
#include "GrayCode.h"

using namespace std;

/// <summary>
/// Функция, заданная в задании: \f$ f(x, y) = x^2 + 100 * (y - 1)^2 - 1 \f$
/// </summary>
/// <param name="x">Параметр x</param>
/// <param name="y">Параметр y</param>
/// <returns>Значение функции</returns>
double f(double x, double y)
{
	return x * x + 100 * pow((y - 1), 2) - 1;
}

int main()
{
	OSOB a("1111");
	cout << "ПДК: " << a << endl;
	OSOB b = toGrayCode(a);
	cout << "код Грея: " << b << endl;
	OSOB c = toPosCode(b);
	cout << "назад в ПДК: " << c << endl;
	return 0;
}


