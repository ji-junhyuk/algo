#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, bomb, ans;;

	cin >> s >> bomb;
	ans = "";
	int bomb_last_idx = bomb.length() - 1;
	for (int idx = 0; idx < s.length(); idx++)
	{
		ans.push_back(s[idx]);
		if (ans[ans.length() - 1] == bomb[bomb_last_idx])
		{
			if (ans.length() >= bomb.length())
			{
				int cnt = 1;
				for (int jdx = bomb_last_idx - 1; jdx >= 0; jdx--)
					if (ans[ans.length() - (bomb_last_idx - jdx) - 1] == bomb[jdx])
						cnt++;
				if (bomb.length() == cnt)
					for (int kdx = 0; kdx < cnt; kdx++)
						ans.pop_back();
			}
		}
	}
	if (ans.length() > 0)
		cout << ans;
	else
		cout << "FRULA";
}
