
#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace Util {
	template <typename T>
	void Swap(T& x, T& y)
	{
		T temp = x;
		x = y;
		y = temp;
	}
}

int main()
{
	int a = 10, b = 20;

	Util::Swap(a, b);

	cout << a << ", " << b << endl;

	double a2 = 10.5, b2 = 20.7;

	Util::Swap(a2, b2);

	cout << a2 << ", " << b2 << endl;

	double a3 = 8.5, b3 = 2.7;

	swap(a3, b3);

	cout << a3 << ", " << b3 << endl;
}