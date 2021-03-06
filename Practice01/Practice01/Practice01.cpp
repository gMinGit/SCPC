/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#include "stdafx.h"
#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int N, temp_num;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		
		cin >> N;

		for (int i = 0; i < N; ++i)
		{
			cin >> temp_num;
			if (i == 0) 
			{
				Answer = temp_num;
			}
			else
			{
				Answer ^= temp_num;
			}
		}
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}