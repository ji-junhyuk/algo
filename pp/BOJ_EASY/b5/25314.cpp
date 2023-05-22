#include <iostream>
using namespace std;
typedef long long ll;

int N;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 0; idx < N / 4; ++idx)
		cout << "long ";
	cout << "int";
}
