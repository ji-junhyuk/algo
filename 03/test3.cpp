#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	vector<int> v1 = {1, 2, 3, 4, 5, 6};

	for (int e : v1)
		cout << e << ' ';

	cout << '\n';
	int i = 0;
	while (i < v1.size())
	{
		cout << v1[i] << ' ';
		i++;
	}

	cout << '\n';
	i = 0;
	while (i < v1.size() - 1)
	{
		cout << v1[i] << ' ';
		i++;
	}
	cout << '\n' << v1.size();
}
