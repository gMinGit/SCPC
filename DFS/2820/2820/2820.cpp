// 2820.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int Pay[500000];
vector<int> Junior[500000];

int N;
int M;

void Calc_Pay(int Boss, int Increment);

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			cin >> Pay[i];
		}
		else
		{
			int temp;
			cin >> Pay[i] >> temp;
			Junior[temp - 1].push_back(i);
		}
	}

	char temp;
	for (int i = 0 ; i < M; i++)
	{
		cin >> temp;
		if (temp == 'p')
		{
			int boss, incre;
			cin >> boss >> incre;
			Calc_Pay(boss - 1, incre);
		}
		else
		{
			int number;
			cin >> number;
			cout << Pay[number - 1] << endl;
		}
	}
    return 0;
}

void Calc_Pay(int Boss, int Increment)
{
	if (Junior[Boss].size() == 0)
		return;

	vector<int>::iterator it = Junior[Boss].begin();

	for (; it != Junior[Boss].end(); ++it)
	{
		Pay[*it] += Increment;
		Calc_Pay(*it, Increment);
	}
}