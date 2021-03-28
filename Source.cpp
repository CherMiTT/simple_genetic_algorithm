#include "Source.h"

using namespace std;

double f(double x, double y)
{
	return x * x + 100 * pow((y - 1), 2) - 1;
}

int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}


