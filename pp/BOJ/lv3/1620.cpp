#include <bits/stdc++.h>
using namespace std;

/*
   map(key, value) 자료구조
   key값을 이용해 value값을 찾는다.
*/
   
int is_number(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M; // 포켓몬의 개수, 문제의 개수

	cin >> N >> M;
	map<string, int> poketname;
	map<int, string> poketnumber;
	for (int idx = 0; idx < N; idx++)
	{
		string poketmon_name;
		cin >> poketmon_name;
		poketname.insert({poketmon_name, idx + 1});
		poketnumber.insert({idx + 1, poketmon_name});
	}
	for (int idx = 0; idx < M; idx++)
	{
		string find_name_number;
		find_name_number = "";
		cin >> find_name_number;
		if (!is_number(find_name_number[0]))
			cout << poketname[find_name_number] << '\n';
		else
		{
			//숫자이면
			int result = 0;
			int idx = 0;
			while (find_name_number[idx])
			{
				result *= 10;
				result += find_name_number[idx++] - '0';
			}
			cout << poketnumber[result] << '\n';
		}
		find_name_number = "";
	}
}
