#include <iostream>
using namespace std;
typedef long long ll;

int X, N, a, b;
int result;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> X;
	cin >> N;
	while (N--)
	{
		cin >> a >> b;
		result += (a * b);
	}
	if (result == X)
		cout << "Yes";
	else
		cout << "No";
}
