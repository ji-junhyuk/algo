#include <iostream>
using namespace std;

int R1, R2;
int S;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R1 >> S;
	R2 = (2 * S) - R1;
	cout << R2;
}
