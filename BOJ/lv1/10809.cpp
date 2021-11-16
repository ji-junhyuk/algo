#include <bits/stdc++.h>
using namespace std;

int arr[26];
char word[101];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int first_word[26];
	int idx;
	int first_position;

	idx = -1;
	while (++idx < 26)
		first_word[idx] = -1;
	cin >> word;
	idx = -1;
	while (word[++idx])
	{
		if (first_word[word[idx] - 'a'] == -1)
			first_word[word[idx] - 'a'] = 100;
		if (first_word[word[idx] - 'a'] == 100)
			first_word[word[idx] - 'a'] = idx;
	}
	idx = -1;
	while (++idx < 26)
		cout << first_word[idx] << ' ';
}
