#include <iostream>
#include <list>
using namespace std;
typedef long long ll;

int A, B;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int idx = 1; idx <= T; ++idx)
	{
		cin >> A >> B;
		cout << "Case #" << idx << ": " <<  A + B << '\n';
	}
}
