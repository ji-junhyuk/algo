#include <iostream>
using namespace std;

int j, w;
int sum;
int differ;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> sum >> differ;

	w = (sum - differ) / 2;
	j = sum - w;
	cout << j << '\n' << w;
}
