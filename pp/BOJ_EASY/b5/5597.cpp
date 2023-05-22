#include <iostream>
#include <list>
using namespace std;
typedef long long ll;

int student[30];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int idx = 0; idx < 28; ++idx)
	{
		int temp;
		cin >> temp;
		student[temp - 1] = 1;
	}
	for (int idx = 0; idx < 30; ++idx)
	{
		if (!student[idx])
			cout << idx + 1 << '\n';
	}

}
