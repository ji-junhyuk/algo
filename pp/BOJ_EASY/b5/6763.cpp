#include <iostream>
using namespace std;

int limit, speed;
int gap;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> limit >> speed;
	gap = speed - limit;
	if (gap >= 1 && gap <= 20)
		cout << "You are speeding and your fine is $100.\n";
	else if (gap >= 21 && gap < 31)
		cout << "You are speeding and your fine is $270.\n";
	else if (gap >= 31)
		cout << "You are speeding and your fine is $500.\n";
	else
		cout << "Congratulations, you are within the speed limit!\n";
}
