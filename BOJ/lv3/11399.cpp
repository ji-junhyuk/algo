#include <bits/stdc++.h>
using namespace std;

int p[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int time;

	cin >> N;
	for (int idx = 0; idx < N; idx++)
		cin >> p[idx];
	sort(p, p + N);
	time = 0;
	for (int idx = 0; idx < N; idx++)
		for (int jdx = 0; jdx <= idx; jdx++)
			time += p[jdx];
	cout << time;
}
