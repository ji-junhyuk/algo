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

	int result;

	int a, b, c;
	cin >> a >> b >> c;
	result = a * b * c;

	int digit[10] = {};
	while (result)
	{
		digit[result % 10]++;
		result /= 10;
	}
	for (int i = 0; i < 10; ++i) 
	{
		cout << digit[i] << '\n';
	}
}
