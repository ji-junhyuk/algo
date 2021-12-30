#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	/*
	   전체 옷 경우의 수 - 1 (둘다 안입는 경우 빼주기)
	*/
	int T, n;
	int result;

	cin >> T;
	while (T--)
	{
		map<string, int> m;
		result = 1;
		string cloth = "";
		string category = "";
		cin >> n;
		for (int idx = 0; idx < n; idx++)
		{
			cin >> cloth >> category;
			m[category]++;
		}
		for (auto i : m)
			result *= i.second + 1;
		result -= 1;
		cout << result << "\n";
	}
}
