#include <bits/stdc++.h>
using namespace std;

/*
 * 규칙
1) 1 - (2 + 3) - (4 + 5) - (6 + 7)
2) 1 + 2 - (3 + 4) - (5 + 6) - 7 
최소값 구하기. - 부호가 나올 때부터 빼주면 된다.
*/
int f_stoi(string s1)
{
	int result;
	int idx;

	idx = 0;
	result = 0;
	while (s1[idx])
	{
		result *= 10;
		result += s1[idx++] - '0';
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	string temp;
	int minus_sign;
	
	cin >> s;

	temp = "";
	minus_sign = 0;
	int num = 0;
	for (int idx = 0; idx <= s.size(); idx++)
	{
		if (s[idx] == '+' || s[idx] == '-' || s[idx] == '\0')
		{
			if (minus_sign)
				num -= f_stoi(temp);
			else
				num += f_stoi(temp);
			if (s[idx] == '-')
				minus_sign = 1;
			temp = "";
			continue;
		}
		temp += s[idx];
	}
	cout << num;
}
