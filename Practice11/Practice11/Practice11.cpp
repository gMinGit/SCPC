
#include "stdafx.h"
#include <iostream>
#define MAX_STONE	1000000
using namespace std;

int Answer;

int Stone_pos[MAX_STONE];

int N; // 돌 갯수.
int K; // 최대 이동 거리

int last_stone;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N; 

		for (int i = 0; i < N; i++)
		{
			cin >> last_stone;
			Stone_pos[i] = last_stone;
		}

		cin >> K;

		Answer = 0;

		int cur_pos = 0;
		int next_pos = 0;
		int start = 0;
		for (; cur_pos != last_stone;)
		{
			next_pos = 0;
			for (int i = start; i < N; i++)
			{
				if (Stone_pos[i] <= cur_pos + K)
				{
					next_pos = Stone_pos[i];
				}
				else
				{
					start = i;
					break;
				}
			}
			if (next_pos == 0)
			{
				Answer = -1;
				break;
			}
			else
			{
				Answer++;
				cur_pos = next_pos;
			}
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}