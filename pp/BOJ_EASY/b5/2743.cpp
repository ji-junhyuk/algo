#include <iostream>
#include <list>
using namespace std;
typedef long long ll;

string s1;
int cnt;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s1;
	for (int idx = 0; s1[idx] != 0; idx++)
		++cnt;
	cout << cnt;
}
