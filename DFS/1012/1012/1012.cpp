// 1012.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define MAX_SIZE		52
int farm[MAX_SIZE][MAX_SIZE];  //2 칸씩 패딩
int farm_visit[MAX_SIZE][MAX_SIZE];  // visit 상황
int Test_case;
int width, height;
int cnt;
int cur_cnt;

void dfs(int x, int y);

int main()
{
	int Answer;

	cin >> Test_case;

	for (int T = 0; T < Test_case; T++)
	{
		cin >> width >> height >> cnt;

		// 초기화
		Answer = 0;
		cur_cnt = 0;

		for (int i = 0; i < height + 2; i++)
		{
			for (int j = 0; j < width + 2; j++)
			{
				farm[i][j]			= 0;
				farm_visit[i][j]	= 0;
			}
		}

		for(int i = 0 ; i < cnt; i++)
		{
			int x, y;
			cin >> x >> y;
			farm[y + 1][x + 1] = 1;
		}

		for (int i = 1; i < height + 1; i++)
		{
			for (int j = 1; j < width + 1; j++)
			{
				/*
				if (cur_cnt == cnt)
				{
					goto Done;
				}*/
				if (!farm_visit[i][j] && farm[i][j] == 1)
				{
					dfs(i, j);
					Answer++;
				}
			}
		}
	Done:
		cout << Answer << endl;
	}
    return 0;
}

void dfs(int x, int y)
{
	if (farm_visit[x][y])
		return;

	farm_visit[x][y] = 1;
	cur_cnt++;

	// 상
	if (farm[x - 1][y])
	{
		dfs(x - 1, y);
	} // not exist else
	
	// 하
	if (farm[x + 1][y])
	{
		dfs(x + 1, y);
	} // not exist else
	
	// 좌
	if (farm[x][y - 1])
	{
		dfs(x, y - 1);
	} // not exist else

	// 우
	if (farm[x][y + 1]) 
	{
		dfs(x, y + 1);
	} // not exist else
}
