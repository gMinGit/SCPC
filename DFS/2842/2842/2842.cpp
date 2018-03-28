// 2842.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int N;

struct {
	int nValue;
	int Height;
	bool Visit;
}typedef MAP;

MAP map[50][50];

int main()
{
	int start_x, start_y;
	char temp;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			if (temp == 'K')
				map[i][j].nValue = 0;
			else if (temp == 'P')
			{
				map[i][j].nValue = 1;
				start_x = i;
				start_y = j;
			}
			else
				map[i][j].nValue = 2;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j].Height;
			map[i][j].Visit = false;
		}
	}
    return 0;
}

