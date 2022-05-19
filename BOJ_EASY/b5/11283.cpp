#include <iostream>
using namespace std;

char str[25];
int valid_digit[16] = {0, 1, 2, 3, 4, 5, 8, 9, 10, 11, 12 ,13, 16, 17, 18, 19};

int	base, pos, ans;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	pos = 24;
	cin >> str;
	for (int i = 0; str[i]; ++i)
	{
		for (int j = 7; j >= 0; --j)
		{
			--pos;
			if (str[i] & (1 << j))
				base = base + (1 << pos);
		}
	}
	for (int i = 0; i < 16; i++)
	{
		if (base & (1 << valid_digit[i]))
			ans = ans + (1 << i);
	}
	cout << ans - 44031;
}
