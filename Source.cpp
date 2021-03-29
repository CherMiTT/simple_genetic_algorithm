/**
* \file
* \brief Основной файл программы
* \author CherMi
* \date	28.03.2021
* \version 1.0
*/


#include "Source.h"

using namespace std;

const double a = -10, b = 10; /// Границы для переменной x
const double c = -10, d = 10; /// Границы для переменной y
const double eps = 0.0001; /// Заданная точность

/// <summary>
/// Функция, заданная в задании: \f$ f(x, y) = x^2 + 100 * (y - 1)^2 - 1 \f$
/// </summary>
/// <param name="x">Параметр x</param>
/// <param name="y">Параметр y</param>
/// <returns>Значение функции f(x, y)</returns>
double f(double x, double y)
{
	return x * x + 100 * pow((y - 1), 2) - 1;
}

/** \brief Ставит в соответсвие десятичному числу из диапазона [A, B] двоичное число
* \param A, B - границы отрезка [A, B]
* \param eps - точность, с которой рассматривается отрезок
* \param number - десятичное число, которому в соответсвие ставим ПДК
* \return Соответсвующую особь в позиционном двоичном коде
*/
singleOsob doubleToOsob(double A, double B, double eps, double number)
{
	number = number / eps + fabs(A) / eps;
	return singleOsob(number);
}


/** \brief Ставит в соответсвие особи в позиционном двоичном коде десятичное число из диапазона [A, B]
* \param A, B - границы отрезка [A, B]
* \param eps - точность, с которой рассматривается отрезок
* \param osob - особь в ПДК
* \return Соответсвующее десятичное число
*/
double osobToDouble(double A, double B, double eps, singleOsob osob)
{
	double number = (double) osob.to_ulong();
	return (number - fabs(A / eps)) * eps;
}

Osob::Osob()
{
	this->x = singleOsob(0);
	this->y = singleOsob(0);
}


/** \bried Конструктор
* \param x - набор генов для координаты x
* \param y - набор генов для координаты y
*/
Osob::Osob(singleOsob x, singleOsob y)
{
	this->x = x;
	this->y = y;
}

/// \brief Деструктор
/// \TODO: заполнить чем-то или удалить
Osob::~Osob()
{

}

/** \brief Создаёт строку, состоящую из генов x, а затем через пробелгенов y, хранящихся в экземпляре класса
* \return Созданную строку
*/
std::string Osob::toString()
{
	return x.to_string() + " " + y.to_string();
}

/** \brief Создаёт строку, состоящую из генов x, а затем через пробел генов y
* \param x, y - наборы генов
* \return Созданную строку
*/
std::string Osob::toString(singleOsob x, singleOsob y)
{
	return x.to_string() + " " + y.to_string();
}

bool operator==(const Osob& left, const Osob& right)
{
	if (left.x == right.x && left.y == right.y) return true;
	else return false;
}

/** \brief Распечатывает в консоль популяцию
* \param p - массив популяции
* \param A, B - границы отрезка, на котором могут быть десятичные числа координаты x
* \param C, D - границы отрезка, на котором могут быть десятичные числа координаты y
* \param eps - точность, с которой просматриваем отрезки
*/
void printPopulation(std::array<Osob, 20> &p, const double &A, const double &B, const double &C, const double &D, const double &eps)
{
	for (Osob& o : p)
	{
		cout << o.toString();
		double x = osobToDouble(A, B, eps, toPosCode(o.x));
		double y = osobToDouble(C, D, eps, toPosCode(o.y));
		cout << "    x = " << x << "; y = " << y;
		cout << "    f(x, y) = " << f(x, y) << endl;
	}
}

/** \brief Распечатывает в особи из вектора
* \param v - вектор особей
* \param A, B - границы отрезка, на котором могут быть десятичные числа координаты x
* \param C, D - границы отрезка, на котором могут быть десятичные числа координаты y
* \param eps - точность, с которой просматриваем отрезки
*/
void printVOsobs(std::vector<Osob> &v, const double& A, const double& B, const double& C, const double& D, const double& eps)
{
	for (Osob& o : v)
	{
		cout << o.toString();
		double x = osobToDouble(A, B, eps, toPosCode(o.x));
		double y = osobToDouble(C, D, eps, toPosCode(o.y));
		cout << "    x = " << x << "; y = " << y;
		cout << "    f(x, y) = " << f(x, y) << endl;
	}
}

/** \brief Создаёт новое поколение из 10 лучших особей предыдущего, меняя рандомный бит в каждой координате
* \param p - массив популяции
*/
void createNewGeneration(std::array<Osob, 20> &p)
{
	for (int i = 0; i < 10; i++)
	{
		singleOsob x = p[i].x;
		singleOsob y = p[i].y;
		x.flip(rand() % 18);
		y.flip(rand() % 18);
		p[i + 10] = Osob(x, y);
	}
}


/** \brief Добавляет 5 лучших особей в популяцию вместо 5 худших (если их там ещё нет) и сортирует её
* \param p - популяция
* \param v - вектор из 5 лучших особей
*/
void shuffleBestOsobsIntoPopulation(std::array<Osob, 20> &p, std::vector<Osob> &v)
{
	bool flag;
	for (int i = 0; i < 5; i++)
	{
		flag = true;
		Osob tmp = v.at(i);
		for (auto& o : p)
		{
			if (o == tmp) flag = false;
		}
		if (flag)
		{
			p.at(i + 14) = tmp;
			cout << "Added best Osob #" << i << endl;
		}
		else
		{
			cout << "Best Osob # " << i << " is already within population" << endl;
		}
	}
	sort(p.begin(), p.end(), compare);
}


/** \brief Сохраняет 5 лучших особей популяции в вектор, сортирует его и оставляет там только пять лучших особей всех поколений
* \param p - массив популяции
* \param v - вектор с лучшими особями
*/
void saveBestOsobs(std::array<Osob, 20>& p, std::vector<Osob>& v)
{
	v.reserve(10);
	bool flag;
	for (int i = 0; i < 5; i++) //Копируем 5 лучших особей
	{
		flag = true;
		Osob tmp = p.at(i);
		for (auto& o : v)
		{
			if (tmp == o) flag = false;
		}
		if (flag)
		{
			v.push_back(p.at(i));
			cout << "Added Osob #" << i << " to bestOsobs" << endl;
		}
		else
		{
			cout << "Osob # " << i << " is already within bestOsobs" << endl;
		}

	}
	sort(v.begin(), v.end(), compare);
	v.resize(5);
}

/** \brief функция-компаратор для std::sort. Возвращает true, если у o1 меньшее значение функции
* \param o1, o2 - сравниваемые особи
*/
bool compare(Osob& o1, Osob& o2) 
{
	return f(osobToDouble(a, b, eps, toPosCode(o1.x)), osobToDouble(c, d, eps, toPosCode(o1.y))) < f(osobToDouble(a, b, eps, toPosCode(o2.x)), osobToDouble(c, d, eps, toPosCode(o2.y)));
}


int main()
{
	size_t generation_count = 0; /// Номер текущего поколения
	array<Osob, 20> population; /// Массив, содержащий популяцию
	vector<Osob> bestOsobs; /// Массив, пяти лучщих особей

	//const size_t N = 20; /// величина популяции
	//TODO: N

	srand(time(0));

	//Генерируем начальную популяцию
	for (Osob& o : population)
	{
		singleOsob x(0);
		singleOsob y(0);
		x.flip(rand() % 18);
		y.flip(rand() % 18);
		o = Osob(x, y);
	}
	
	sort(population.begin(), population.end(), compare);
	saveBestOsobs(population, bestOsobs);

	cout << "Generation №" << ++generation_count << endl;
	printPopulation(population, a, b, c, d, eps);

	for (int i = 0; i < 99; i++)
	{
		shuffleBestOsobsIntoPopulation(population, bestOsobs);
		createNewGeneration(population);
		sort(population.begin(), population.end(), compare);
		saveBestOsobs(population, bestOsobs);
		cout << "Generation №" << ++generation_count << endl;
		printPopulation(population, a, b, c, d, eps);
	}

	cout << "*********************************************************************************************************************" << endl;
	cout << "Best osobs of all time:" << endl;
	printVOsobs(bestOsobs, a, b, c, d, eps);
	return 0;
}