#include <iostream>
using namespace std;

int	N;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cout << (N * (N - 1));
}
