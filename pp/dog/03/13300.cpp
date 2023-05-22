#include <bits/stdc++.h>
using namespace std;

int person[2][6];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int people_number;
	int room_number;
	int idx;
	int jdx;
	int gender;
	int grade;
	int room;

	cin >> people_number;
	cin >> room_number;
	idx = -1;
	while (++idx < people_number)
	{
		cin >> gender;
		cin >> grade;
		person[gender][grade - 1]++;
	}
	idx = -1;
	room = 0;
	while (++idx < 2)
	{
		jdx = -1;
		while (++jdx < 6)
			room += ((person[idx][jdx] + (room_number - 1)) / room_number);
	}
	cout << room;
}
