#include <iostream>
#include <list>
using namespace std;
typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 100;
	string s1;
	getline(cin, s1);
	while (s1 != "")
	{
		cout << s1 << '\n';
		getline(cin, s1);
	}
}
