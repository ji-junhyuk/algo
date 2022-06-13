#include <iostream>
using namespace std;
typedef long long ll;

int	A, B, C, D;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B >> C >> D;
	
	C += D;
	B += (C / 60);
	A += (B / 60);

	cout << A % 24 << ' ' << B % 60 << ' ' << C % 60;
}
