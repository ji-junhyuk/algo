#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) 
	{
		string a, b;
		cin >> a >> b;
		int a_alpha[26] = {};
		int b_alpha[26] = {};
		for (int i = 0; i < a.size(); ++i) 
		{
			a_alpha[a[i] - 'a']++;
		}
		for (int i = 0; i < a.size(); ++i) 
		{
			b_alpha[b[i] - 'a']++;
		}
		bool flag = true;
		for (int i = 0; i < 26; ++i) 
		{
			if (a_alpha[i] != b_alpha[i])
			{
				flag = false;
			}
		}
		if (flag)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}
}
