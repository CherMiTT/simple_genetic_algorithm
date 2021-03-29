/**
* \file
* \brief Основной файл программы
* \author CherMi
* \date	28.03.N21
* \version 1.0
*/


#include "Source.h"

using namespace std;

///Границы для переменной x
const double a = -10, b = 10;

/// Границы для переменной y
const double c = -10, d = 10;
///Заданная точность
const double eps = 0.0001; 

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
void printPopulation(std::array<Osob, N> &p, const double &A, const double &B, const double &C, const double &D, const double &eps)
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

/** \brief Мутирует все особи популяци, меняя рандомный бит в каждой координате
* \param p - массив популяции
*/
void mutatePopulation(std::array<Osob, N> &p)
{
	for (auto& o : p)
	{
		o.x.flip(rand() % M);
		o.y.flip(rand() % M);
	}
}

/** \brief Кроссинговером создаёт 40 новых особей, N лучших записывает в популяцию в отсортированном порядке
*
*/
void breedNewGeneration(std::array<Osob, N>& p)
{
	array<Osob, 40> newOsobs;
	int first_parent, second_parent;
	for (int i = 0; i < 40; i++)
	{
		first_parent = rand() % N;
		second_parent = rand() % N;

		singleOsob x, y;
		int j_x, j_y, pred_x, pred_y;
		pred_x = rand() % M;
		for (j_x = 0; j_x < pred_x; j_x++)
		{
			x[j_x] = p[first_parent].x[j_x];
		}
		for (; j_x < M; j_x++)
		{
			x[j_x] = p[second_parent].x[j_x];
		}

		pred_y = rand() % M;
		for (j_y = 0; j_y < pred_y; j_y++)
		{
			y[j_y] = p[first_parent].x[j_y];
		}
		for (; j_y < M; j_y++)
		{
			y[j_y] = p[second_parent].x[j_y];
		}

		newOsobs[i] = Osob(x, y);
	}

	sort(newOsobs.begin(), newOsobs.end(), compare);
	for (int i = 0; i < N; i++)
	{
		p[i] = newOsobs[i];
	}
}

/** \brief Добавляет 5 лучших особей в популяцию вместо 5 худших (если их там ещё нет) и сортирует её
* \param p - популяция
* \param v - вектор из 5 лучших особей
*/
void shuffleBestOsobsIntoPopulation(std::array<Osob, N> &p, std::vector<Osob> &v)
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
			//cout << "Added best Osob #" << i << endl;
		}
		else
		{
			//cout << "Best Osob # " << i << " is already within population" << endl;
		}
	}
	sort(p.begin(), p.end(), compare);
}


/** \brief Сохраняет 5 лучших особей популяции в вектор, сортирует его и оставляет там только пять лучших особей всех поколений
* \param p - массив популяции
* \param v - вектор с лучшими особями
*/
void saveBestOsobs(std::array<Osob, N>& p, std::vector<Osob>& v)
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
			//cout << "Added Osob #" << i << " to bestOsobs" << endl;
		}
		else
		{
			//cout << "Osob # " << i << " is already within bestOsobs" << endl;
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
	array<Osob, N> population; /// Массив, содержащий популяцию
	vector<Osob> bestOsobs; /// Массив, пяти лучщих особей

	srand(time(0));

	//Генерируем начальную популяцию
	mutatePopulation(population);
	sort(population.begin(), population.end(), compare);
	saveBestOsobs(population, bestOsobs);

	cout << "Generation №" << ++generation_count << endl;
	printPopulation(population, a, b, c, d, eps);

	for (int i = 0; i < 49; i++)
	{
		shuffleBestOsobsIntoPopulation(population, bestOsobs);
		breedNewGeneration(population);
		saveBestOsobs(population, bestOsobs);
		mutatePopulation(population);
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