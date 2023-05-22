#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int height;
	int hillup;
	int down;

	cin >> hillup >> down >> height;

	int dayup;
	int new_height;

	dayup = hillup - down;
	new_height = height - down; // 마지막날은 내려가지 않으니
	if (new_height % dayup)
		cout << new_height / dayup + 1;
	else
		cout << new_height / dayup;
}
