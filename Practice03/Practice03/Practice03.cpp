
#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int score[200000];

int N, K;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> N >> K;

		for (int i = 0; i < N; ++i) {
			cin >> score[i];
		}

		sort(score, score + N);

		for (int i = 0; i < K; i++) {
			Answer += score[ (N - 1) - i ];
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}