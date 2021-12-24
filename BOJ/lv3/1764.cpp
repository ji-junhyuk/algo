#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<string, int> m;
	vector<string> v;
	int N, M;
	cin >> N >> M;
	for (int idx = 0; idx < N + M; idx++)
	{
		string str;
		cin >> str;
		m[str]++;
		if (m[str] > 1)
			v.push_back(str);
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (auto c : v)
		cout << c << '\n';
}
