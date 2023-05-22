#include <iostream>
#include <climits>
using namespace std;

long long A, B;
long long cnt = 1;
long long find_min = LONG_MAX;

void dfs(long long A, long long cnt)
{
	if (A > B)
		return ;
	if (A == B)
		find_min = min(find_min, cnt);
	dfs(A * 2, cnt + 1);
	dfs(A * 10 + 1, cnt + 1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;
	dfs(A, cnt);
	if (find_min == LONG_MAX)
		cout << -1;
	else
		cout << find_min;
}
