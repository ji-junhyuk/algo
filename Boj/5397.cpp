#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		string s;
		list<char> L;
		cin >> s;
		auto cursor = L.end();
		for (auto c : s)
		{
			if (c == '<')
			{
				if (cursor != L.begin())
					--cursor;
			}
			else if (c == '>')
			{
				if (cursor != L.end())
					++cursor;
			}
			else if (c == '-')
			{
				if (cursor != L.begin())
				{
					--cursor;
					cursor = L.erase(cursor);
				}
			}
			else 
			{
				L.insert(cursor, c);
			}
		}
		for (auto c : L)
			cout << c;
	}
}
