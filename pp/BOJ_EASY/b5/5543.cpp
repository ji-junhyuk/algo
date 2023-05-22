#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int burger[3];
	int beverage[2];
	
	for (int idx = 0; idx < 3; ++idx)
		cin >> burger[idx];
	for (int idx = 0; idx < 2; ++idx)
		cin >> beverage[idx];
	int set_menu;
	set_menu = 2000;
	for (int idx = 0; idx < 3; ++idx)
	{
		for (int jdx = 0; jdx < 2; ++jdx)
		{	
			int temp;
			temp = burger[idx] + beverage[jdx];
			if (set_menu > temp)
				set_menu = temp;
		}
	}
	cout << set_menu - 50;
}
