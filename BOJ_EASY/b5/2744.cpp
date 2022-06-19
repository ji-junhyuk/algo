#include <iostream>
#include <list>
using namespace std;
typedef long long ll;

string s1;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s1;
	for (int idx = 0; s1[idx] != 0; ++idx)
	{
		if (s1[idx] >= 'a' && s1[idx] <= 'z')
			s1[idx] = s1[idx] - 'a' + 'A';
		else
			s1[idx] = s1[idx] - 'A' + 'a';
	}
	cout << s1;
}
