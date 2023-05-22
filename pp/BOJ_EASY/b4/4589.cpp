#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int N;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int a, b, c;
	cout << "Gnomes:\n";
	for (int idx = 0; idx < N; ++idx)
	{
		cin >> a >> b >> c;
		if (a < b && b < c)
			cout << "Ordered\n";
		else if (a > b && b > c)
			cout << "Ordered\n";
		else
			cout << "Unordered\n";
	}
}
