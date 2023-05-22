#include <iostream>
using namespace std;
typedef long long ll;

int	A, B;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;
	cout << A * (B % 10) << '\n';
	cout << A * ((B / 10) % 10) << '\n';
	cout << A * (B / 100 % 100) << '\n';
	cout << A * B;
}
