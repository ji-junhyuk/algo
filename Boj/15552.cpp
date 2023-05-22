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

	int T;
	int a, b;
	cin >> T;
	for (int i = 0; i < T; ++i) 
	{
		cin >> a >> b;
		cout << a + b << '\n';
	}
}
