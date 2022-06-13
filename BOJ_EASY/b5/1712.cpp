#include <iostream>
using namespace std;
typedef long long ll;

ll A, B, C;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B >> C;
	if (B >= C)
	{
		cout << "-1";
		return (0);
	}
	cout << A / (C - B) + 1;
}
