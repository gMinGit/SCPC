// 6603.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int k;
int S[20];
bool S_visit[20];


void dfs(int cnt, int x = 0);

int main()
{
	while (1)
	{
		cin >> k;

		if (k == 0)
			break;

		for (int i = 0; i < k; i++)
		{
			cin >> S[i];
			S_visit[i] = false;
		}

		dfs(0);

		cout << endl;
	}
    return 0;
}

void dfs(int cnt, int x)
{
	if (x == k)
	{
		if(cnt == 6)
		{
			for (int i = 0; i < k; i++)
			{
				if(S_visit[i])
					cout << S[i] << " ";
			}
			cout << endl;
		}

		return;
	}

	S_visit[x] = true;
	cnt++;
	dfs(x + 1, cnt);
	
	S_visit[x] = false;
	dfs(x + 1, cnt);

}

