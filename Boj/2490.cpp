#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;

	for (int i = 0; i < 3; ++i) 
	{
		int score = 0;
		for (int i = 0; i < 4; ++i) 
		{
			cin >> num;
			score += num;
		}
		if (score == 0)
		{
			cout << "D";
		}
		else if (score == 1)
		{
			cout << "C";
		}
		else if (score == 2)
		{
			cout << "B";
		}
		else if (score == 3)
		{
			cout << "A";
		}
		else
		{
			cout << "E";
		}
		cout << '\n';
	}
}
