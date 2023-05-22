#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

int number;
int car[5];
int cnt;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> number;
	for (int i = 0; i < 5; i++) {
		cin >> car[i];
		if (number == car[i])
			++cnt;
	}
	cout << cnt;
}
