// 10026.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Map{
	int color[2]	= { 0, };
	bool visit[2]	= { false, false };
};

Map rgb_map[100][100];
int N;

int cnt = 0, cnt2 = 0;

void dfs(int x, int y, int index);

int main()
{
	char RGB_String[100];

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> RGB_String;
		for (int j = 0; j < N; j++)
		{
			rgb_map[i][j].color[0] = RGB_String[j];
			if (RGB_String[j] == 'G')
			{
				rgb_map[i][j].color[1] = 'R';
			}
			else
			{
				rgb_map[i][j].color[1] = RGB_String[j];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!rgb_map[i][j].visit[0])
			{
				cnt++;
				dfs(i, j, 0);
			}

			if (!rgb_map[i][j].visit[1])
			{
				cnt2++;
				dfs(i, j, 1);
			}
		}
	}

	cout << cnt << " " << cnt2 << endl;

    return 0;
}

void dfs(int x, int y, int index)
{
	if (rgb_map[x][y].visit[index])
		return;

	rgb_map[x][y].visit[index] = true;

	int my_color = rgb_map[x][y].color[index];

	if (x > 0 && my_color == rgb_map[x - 1][y].color[index])
	{
		dfs(x - 1, y, index);
	}

	if (x < N - 1 && my_color == rgb_map[x + 1][y].color[index])
	{
		dfs(x + 1, y, index);
	}

	if (y > 0 && my_color == rgb_map[x][y - 1].color[index])
	{
		dfs(x, y - 1, index);
	}

	if (y < N -1 && my_color == rgb_map[x][y + 1].color[index])
	{
		dfs(x, y + 1, index);
	}
}