
#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int Answer;
const int score[] = { 6, 13,  4, 18,  1,
					 20,  5, 12,  9, 14,
					 11,  8, 16,  7, 19,
					  3, 17,  2, 15, 10 };

int a, b, c, d, e;
int N;

#define BULL_SIZE		a*a
#define DOUBLE_INSIZE	d*d
#define DOUBLE_OUTSIZE	e*e
#define TRIPLE_INSIZE	b*b
#define TRIPLE_OUTSIZE	c*c

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;

		cin >> a >> b >> c >> d >> e;

		cin >> N;

		for (int i = 0; i < N; ++i) {
			double xpos, ypos;

			cin >> xpos >> ypos;

			int size = 0;
			double angle = atan2(ypos, xpos) *180 / 3.141592;
			
			if (angle < 0) 
				angle += 360;

			int degree = (int((angle + 9)) % 360);

			size = xpos * xpos + ypos * ypos;
			if (size <= BULL_SIZE) //bull
			{
				Answer += 50;
			}
			else if (size >= TRIPLE_INSIZE && size <= TRIPLE_OUTSIZE) //triple
			{
				Answer += score[degree /18]*3;
			}
			else if (size >= DOUBLE_INSIZE && size <= DOUBLE_OUTSIZE) //double
			{
				Answer += score[degree / 18] *2;
			}
			else if (size > DOUBLE_OUTSIZE) // out board
			{
				Answer += 0;
			}
			else							// single
			{
				Answer += score[degree / 18];
			}
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}