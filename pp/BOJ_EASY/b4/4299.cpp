#include <iostream>
using namespace std;
typedef long long ll;

int	sum, differ;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> sum >> differ;
	for (int idx = 0; idx < 1001; ++idx)
	{
		for (int jdx = 0; jdx < 1001; ++jdx)
		{
			if (idx + jdx == sum && idx - jdx == differ)
			{
				if (idx >= jdx)
					cout << idx << ' ' << jdx;
				else 
					cout << jdx << ' ' << idx;
				return (0);
			}
		}
	}
	cout << -1;
	return (0);
}
