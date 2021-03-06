// 1987.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int Row, Width;
int max = -1;

bool history[26] = {0,};
char** board;

void dfs(int x, int y, bool* m_history, int cnt);

int main()
{
	char temp[100];

	cin >> Row >> Width;

	board = new char*[Row];

	for (int i = 0; i < Row; ++i)
	{
		board[i] = new char[Width];
	}

	for (int i = 0; i < Row; ++i)
	{
		cin >> temp;
		for (int j = 0; j < Width; ++j)
		{
			board[i][j] = temp[j] - 65;
		}
	}

	history[board[0][0]] = true;

	dfs(0, 0, history, 1);

	cout << ::max << endl;

    return 0;
}

void dfs(int x, int y, bool* m_history, int cnt)
{
	bool myhistory[26];
	for (int i = 0; i < 26; i++)
		myhistory[i] = m_history[i];

	if (x > 0 && !myhistory[board[x - 1][y]])
	{
		myhistory[board[x - 1][y]] = true;
		cnt++;
		dfs(x - 1, y, myhistory, cnt);
		myhistory[board[x - 1][y]] = false;
		cnt--;
	}
	if (x < Row - 1 && !myhistory[board[x + 1][y]]) // 하
	{
		myhistory[board[x + 1][y]] = true;
		cnt++;
		dfs(x + 1, y, myhistory, cnt);
		myhistory[board[x + 1][y]] = false;
		cnt--;
	}
	if (y > 0 && !myhistory[board[x][y - 1]]) // 좌
	{
		myhistory[board[x][y - 1]] = true;
		cnt++;
		dfs(x, y - 1, myhistory, cnt);
		myhistory[board[x][y - 1]] = false;
		cnt--;
	}
	if (y < Width - 1 && !myhistory[board[x][y + 1]])	// 우
	{
		myhistory[board[x][y + 1]] = true;
		cnt++;
		dfs(x, y + 1, myhistory, cnt);
		myhistory[board[x][y + 1]] = false;
		cnt--;
	}

	if (::max < cnt)
		::max = cnt;
}