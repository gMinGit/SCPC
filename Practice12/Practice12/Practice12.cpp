#include "stdafx.h"
#include <iostream>

using namespace std;

int Answer;
int N;

#define MAX_SIZE	1002

#define FROM_UP(pre_i, pre_j, cur_i, cur_j)			(pre_i < cur_i)&&(pre_j == cur_j)
#define FROM_DOWN(pre_i, pre_j, cur_i, cur_j)		(pre_i > cur_i)&&(pre_j == cur_j)
#define FROM_LEFT(pre_i, pre_j, cur_i, cur_j)		(pre_i == cur_i)&&(pre_j < cur_j)
#define FROM_RIGHT(pre_i, pre_j, cur_i, cur_j)		(pre_i == cur_i)&&(pre_j > cur_j)

#define GO_UP(pre_i, pre_j, cur_i, cur_j)			do{(pre_i) = (cur_i); (pre_j) = (cur_j); (cur_i)--;}while(0);
#define GO_DOWN(pre_i, pre_j, cur_i, cur_j)		do{(pre_i) = (cur_i); (pre_j) = (cur_j); (cur_i)++;}while(0);
#define GO_LEFT(pre_i, pre_j, cur_i, cur_j)		do{(pre_i) = (cur_i); (pre_j) = (cur_j); (cur_j)--;}while(0);
#define GO_RIGHT(pre_i, pre_j, cur_i, cur_j)		do{(pre_i) = (cur_i); (pre_j) = (cur_j); (cur_j)++;}while(0);

char room[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];

int main(int argc, char** argv)
{
	int T, test_case;

	int Pre_i, Pre_j;
	int Cur_i, Cur_j;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			for (int j = 0; j < MAX_SIZE; j++)
				visit[i][j] = false;
		}

		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> room[i][j];
			}
			cin.ignore();
		}

		Answer = 0;

		Pre_i = 1;
		Pre_j = 0;
		Cur_i = 1;
		Cur_j = 1;

		while (Cur_i != 0 && Cur_i != N + 1
			&& Cur_j != 0 && Cur_j != N + 1)
		{
			if (room[Cur_i][Cur_j] == '0')
			{
				if (FROM_UP(Pre_i, Pre_j, Cur_i, Cur_j))
				{
					GO_DOWN(Pre_i, Pre_j, Cur_i, Cur_j);
				}
				else if (FROM_DOWN(Pre_i, Pre_j, Cur_i, Cur_j))
				{
					GO_UP(Pre_i, Pre_j, Cur_i, Cur_j);
				}
				else if (FROM_LEFT(Pre_i, Pre_j, Cur_i, Cur_j))
				{
					GO_RIGHT(Pre_i, Pre_j, Cur_i, Cur_j);
				}
				else if (FROM_RIGHT(Pre_i, Pre_j, Cur_i, Cur_j))
				{
					GO_LEFT(Pre_i, Pre_j, Cur_i, Cur_j);
				}
			}
			else if (room[Cur_i][Cur_j] == '1')			//     / 모양의 창문
			{
				if (FROM_UP(Pre_i, Pre_j, Cur_i, Cur_j))
				{
					GO_LEFT(Pre_i, Pre_j, Cur_i, Cur_j);
				}
				else if (FROM_DOWN(Pre_i, Pre_j, Cur_i, Cur_j))
				{
					GO_RIGHT(Pre_i, Pre_j, Cur_i, Cur_j);
				}
				else if (FROM_LEFT(Pre_i, Pre_j, Cur_i, Cur_j))
				{
					GO_UP(Pre_i, Pre_j, Cur_i, Cur_j);
				}
				else if (FROM_RIGHT(Pre_i, Pre_j, Cur_i, Cur_j))
				{
					GO_DOWN(Pre_i, Pre_j, Cur_i, Cur_j);
				} // not exist else statement

				if (visit[Pre_i][Pre_j] == false)
				{
					visit[Pre_i][Pre_j] = true;
					Answer++;
				}
			}
			else if (room[Cur_i][Cur_j] == '2')          // ↘ 모양의 창문
			{
				if (FROM_UP(Pre_i, Pre_j, Cur_i, Cur_j))
				{
					GO_RIGHT(Pre_i, Pre_j, Cur_i, Cur_j);
				}
				else if (FROM_DOWN(Pre_i, Pre_j, Cur_i, Cur_j))
				{
					GO_LEFT(Pre_i, Pre_j, Cur_i, Cur_j);
				}
				else if (FROM_LEFT(Pre_i, Pre_j, Cur_i, Cur_j))
				{
					GO_DOWN(Pre_i, Pre_j, Cur_i, Cur_j);
				}
				else if (FROM_RIGHT(Pre_i, Pre_j, Cur_i, Cur_j))
				{
					GO_UP(Pre_i, Pre_j, Cur_i, Cur_j);
				} // not exist else statement

				if (visit[Pre_i][Pre_j] == false)
				{
					visit[Pre_i][Pre_j] = true;
					Answer++;
				}
			}
			else
			{
				; // data error
			}
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}