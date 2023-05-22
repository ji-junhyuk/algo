#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

void	calculate(int score[])
{
	sort(score, score + 3);
	if (score[0] == score[1] && score[1] == score[2] )
	{
		cout << 10000 + score[1] * 1000;
	}
	else if (score[0] == score[1] || score[0] == score[2])
	{
		cout << 1000 + score[0] * 100;
	}
	else if (score[1] == score[2])
	{
		cout << 1000 + score[1] * 100;
	}
	else
	{
		cout << score[2] * 100;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int score[3];
	for (int i = 0; i < 3; ++i) 
	{
		cin >> score[i];
	}
	calculate(score);
}
