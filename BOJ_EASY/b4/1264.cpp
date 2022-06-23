#include <iostream>
#include <list>
using namespace std;
typedef long long ll;


int cnt;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		string s1;
		getline(cin, s1);
		if (s1 == "#")
			break ;
		for (int idx = 0; s1[idx] != 0; ++idx)
		{
			if (s1[idx] == 'a' || s1[idx] == 'e' || s1[idx] == 'i' || s1[idx] == 'o' || s1[idx] == 'u' ||
			s1[idx] == 'A' || s1[idx] == 'E' || s1[idx] == 'I' || s1[idx] == 'O' || s1[idx] == 'U')
				cnt++;
		}
		cout << cnt << '\n';
		cnt = 0;
	}
}
