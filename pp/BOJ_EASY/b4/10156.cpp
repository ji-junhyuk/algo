#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int K, N, M;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> N >> M;
	
	int cost = K * N;

	if (cost > M)
		cout << (K * N - M);
	else
		cout << 0;
}
