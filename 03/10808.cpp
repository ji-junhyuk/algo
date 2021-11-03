#include <bits/stdc++.h>
using namespace std;

char alpha[26];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	char input[100];
	cin >> input;
	int i;
	i = 0;
	while (input[i])
	{
		if (input[i] >= 'a' && input[i] <= 'z')
			alpha[input[i] - 'a']++;
		i++;
	}
	i = 0;
	while (i < 26)
	{
//		printf("%d ", alpha[i]);
		cout << alpha[i] + 0 << ' ';
		i++;
	}
}

//#include <bits/stdc++.h>
//using namespace std;
//
//int freq[26];
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	string s;
//	cin >> s;
//	for (auto c : s)
//		freq[c - 'a']++;
//	for (int i = 0; i < 26; i++)
//		printf("%d ", freq[i]);
////		cout << freq[i] << ' ';
//}
