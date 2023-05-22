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

	int score[5];
	int average = 0;
	for (int i = 0; i < 5; ++i) 
	{
		cin >> score[i];
		average += score[i];
	}
	sort(score, score + 5);
	cout << (average / 5) << '\n';
	cout << score[2] << '\n';
}
