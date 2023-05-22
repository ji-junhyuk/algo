#include <iostream>
#include <list>
using namespace std;
typedef long long ll;

string s1;
int T;
char first;
char last;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--)
	{
		string s1;
		cin >> s1;
		for (int idx = 0; s1[idx] != 0; ++idx)
		{
			first = s1[0];
			if (s1[idx + 1] == 0)
			{
				last = s1[idx];
				cout << first << last << '\n';
			}
		}
	}
}
