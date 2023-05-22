#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int hour;
	int minute;

	cin >> hour >> minute;
	if (minute < 45)
	{
		if (hour == 0)
			hour = 23;
		else
			hour--;
		minute = 60 + (minute - 45);
	}
	else
		minute -= 45;
	cout << hour << ' ' << minute;
}
