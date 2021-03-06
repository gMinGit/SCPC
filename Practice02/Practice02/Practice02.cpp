#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
#define MAX_NUMBER	300000
int arr[MAX_NUMBER];

int main(int argc, char** argv)
{
	int T, test_case;
	int N;
	int max;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		cin >> N;

		Answer = N;
		max = -1;

		for (int i = 0; i < N; ++i) 
		{
			cin >> arr[i];
		}

		sort(arr, arr + N);

		// 최소의 케이스에서 가장 큰 값을 찾자.
		// 최소의 케이스 : 1등부터 차례대로 가장 낮은 점수를 받는 경우
		for (int i = 0; i < N; ++i) 
		{
			if (max < arr[i] + N - i)
				max = arr[i] + N - i;
		}

		for (int i = 0; i < N; ++i)
		{
			// 각자 최고 점수를 받은 값이 최소케이스 맥스값보다 작으면 최종 우승하지 못함.
			if (max > arr[i] + N)
				--Answer;
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}