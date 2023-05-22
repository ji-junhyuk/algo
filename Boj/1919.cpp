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

	string a, b;
	cin >> a >> b;

	int a_alpha[26] = {};
	int b_alpha[26] = {};
	for (int i = 0; i < a.size(); ++i) 
	{
		a_alpha[a[i] - 'a']++;
	}
	for (int i = 0; i < b.size(); ++i) 
	{
		b_alpha[b[i] - 'a']++;
	}
	int diff = 0;
	for (int i = 0; i < 26; ++i) 
	{
		diff += abs(a_alpha[i] - b_alpha[i]);
	}
	cout << diff << '\n';
}
