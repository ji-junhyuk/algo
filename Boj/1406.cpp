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

	string s;
	cin >> s;
	list<char> L;
	int M;
	for (auto c : s)
		L.push_back(c);
	auto cursor = L.end();
	cin >> M;
	while (M--)
	{
		char op;
		cin >> op;
		if (op == 'L')
		{
			if (cursor != L.begin())
				--cursor;
		}
		else if (op == 'D')
		{
			if (cursor != L.end())
				++cursor;
		}
		else if (op == 'B')
		{
			if (cursor != L.begin())
			{
				--cursor;
				cursor = L.erase(cursor);
			}
		}
		else
		{
			char c;
			cin >> c;
			L.insert(cursor, c);
		}
	}
	auto c = L.begin();
	for (auto c : L)
		cout << c;
}
