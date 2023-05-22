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

	int N;
	cin >> N;
	int digits[10] = {};
	while (N)
	{
		digits[N % 10]++;
		N /= 10;
	}
	digits[6] = (digits[6] + digits[9]) / 2 + (digits[6] + digits[9]) % 2;
	digits[9] = digits[6];
	int set = -1;
	for (int i = 0; i < 10; ++i) 
	{
		if (digits[i] > set)
			set = digits[i];
	}
	cout << set << '\n';
}
