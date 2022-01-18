#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; // 주소, 찾으려는 사이트 수
	map<string, string>memo;
	string addr;
	string pwd;

	cin >> N >> M;
	while (N--)
	{
		cin >> addr >> pwd;
		memo.insert({addr, pwd});
	}
	while (M--)
	{
		cin >> addr;
		cout << memo[addr] << '\n';
	}
}
