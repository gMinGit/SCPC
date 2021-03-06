#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int Answer;

int N;

double logB(double x, double base)
{
	return log(x) / log(base);
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N;

		Answer = 2;

		bool Pass = true;

		while(1) {
			int temp;
			temp  = int(logB(N, Answer)) + 1;

			int temp2 = (1 - pow((double)Answer, (double)temp)) / (1 - Answer);

			if (N % temp2 == 0)
			{
				break;
			}
			else
			{
				Answer++;
			}
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}