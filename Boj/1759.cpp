#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int L, C;

string pw;
char c[16];
bool is_consonant[16];
bool is_selected[16];


void	bt(int depth, string &pw, int z, int m, int start)
{
	if (depth == L)
	{
		if (z >= 2 && m >= 1)
		{
			cout << pw << '\n';
		}
		return ;
	}
	for (int i = start; i < C; ++i) 
	{
		if (!is_selected[i])
		{
			is_selected[i] = true;
			pw.push_back(c[i]);
			z += is_consonant[i];
			m += !is_consonant[i];
			bt(depth + 1, pw, z, m, i + 1);
			z -= is_consonant[i]; 
			m -= !is_consonant[i];
			is_selected[i] = false;
			pw.pop_back();
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> C;
	for (int i = 0; i < C; ++i) 
	{
		cin >> c[i];
	}
	sort(c, c + C);
	for (int i = 0; i < C; ++i) 
	{
		if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u')
			is_consonant[i] = 0;
		else
			is_consonant[i] = 1;
	}
	bt(0, pw, 0, 0, 0);
}
