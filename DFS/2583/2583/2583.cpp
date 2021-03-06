// 2583.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int Height, Width, K;
int Map[100][100];
bool Map_visit[100][100];

int answer[10000];
int cnt;
void dfs(int i, int j);

int main()
{
	cin >> Height >> Width >> K;

	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = 0; j < x2 - x1; j++)
		{
			for (int r = 0; r < y2 - y1; r++)
			{
				Map[y1 + r][x1 + j] = 1;
			}
		}
	}

	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if(Map[i][j] == 0 && !Map_visit[i][j])
			{
				dfs(i, j);
				cnt++;
			}
		}
	}

	sort(answer + 0, answer + cnt);

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		cout << answer[i] << " ";
	cout << endl;

    return 0;
}

void dfs(int i, int j)
{
	if (Map_visit[i][j])
		return;

	Map_visit[i][j] = true;
	answer[cnt]++;

	if (i > 0 && Map[i - 1][j] == 0) // 상
	{
		dfs(i - 1, j);
	}

	if (i < Height - 1 && Map[i + 1][j] == 0) // 하
	{
		dfs(i + 1, j);
	}

	if (j > 0 && Map[i][j - 1] == 0) // 좌
	{
		dfs(i, j - 1);
	}

	if (j < Width - 1 && Map[i][j + 1] == 0) // 우
	{
		dfs(i, j + 1);
	}
}