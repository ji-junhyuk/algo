#include <iostream>
#include <list>
using namespace std;
typedef long long ll;

int L, A, B, C, D;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> A >> B >> C >> D;
	int day = 0;
	while (A > 0 || B > 0)
	{
		++day;
		A -= C;
		B -= D;
	}
	cout << L - day;
}
