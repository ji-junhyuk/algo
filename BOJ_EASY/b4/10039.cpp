#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int score[5];
int sum;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int idx = 0; idx < 5; ++idx)
	{
		cin >> score[idx];
		if (score[idx] < 40)
			score[idx] = 40;
		sum += score[idx];
	}
	cout << sum / 5;
}
