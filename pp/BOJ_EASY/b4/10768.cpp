#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

int month, day;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> month >> day;
	if (month < 2 || (month == 2 && day < 18))
		cout << "Before";
	else if (month == 2 && day == 18)
		cout << "Special";
	else
		cout << "After";
}
