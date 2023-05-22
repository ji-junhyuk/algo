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

	int year;

	cin >> year;

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
	{
		cout << 1;
		return (0);
	}
	cout << 0;
}
