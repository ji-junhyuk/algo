#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, M;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	cout << abs(N - M);
}
