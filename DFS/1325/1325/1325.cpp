// 1325.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

#define MAX_CNT			10000

int N, M;
int cur_cnt;

vector<int> relation[MAX_CNT];
int Answer[MAX_CNT];

void dfs(int start);

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		relation[end - 1].push_back(start - 1);
	}

	for (int i = 0; i < N; i++)
	{
		cur_cnt = 0;
		dfs(i);
		Answer[i] = cur_cnt;
	}

	int max = -1;

	for (int i = 0; i < N; i++)
	{
		if (max < Answer[i])
			max = Answer[i];
	}
	for (int i = 0; i < N; i++)
	{
		if (Answer[i] == max)
			cout << i + 1 << " ";
	}
	cout << endl;
	return 0;
}

void dfs(int start) 
{
	vector<int>::iterator iter = relation[start].begin();

	// 반복
	for (iter = relation[start].begin(); iter != relation[start].end(); ++iter) {
		cur_cnt++;
		dfs(*iter);
	}
}