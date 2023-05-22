#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int N, M;
char arr[11][11];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int idx = 0; idx < N; ++idx)
		cin >> arr[idx];
	for (int idx = 0; idx < N; ++idx)
	{
		for (int jdx = M - 1; jdx >= 0; --jdx)
			cout << arr[idx][jdx];
		cout << '\n';
	}
}
