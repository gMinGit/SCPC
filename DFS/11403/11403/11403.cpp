// 11403.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


bool arr[100][100];
bool answer[100][100];

int N;

void dfs(int d, int s);

int main()
{
	int temp;

	cin >> N; 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			arr[i][j] = ( (temp == 0) ? false : true);
			answer[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++)
		dfs(i, i);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++){
			if (answer[i][j])
				cout << "1";
			else
				cout << "0";

			if (j != N - 1)
				cout << " ";
		}
		cout << endl;
	}
    return 0;
}

void dfs(int d, int s)
{
	for(int i = 0; i < N ; i++){
		if (arr[d][i] == true && i == s) {
			answer[s][i] = true;
		}
		else if (arr[d][i] == true && !answer[s][i]){
			answer[s][i] = true;
			dfs(i, s);
		}
	}
}