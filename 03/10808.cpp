/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

char alpha[101];
char number[27];
int main()
{
    int i;
    
    cin >> alpha;
    i = -1;
    while (++i < 100)
        number[alpha[i] - 'a']++;
    i = -1;
    while (++i < 26)
        cout << number[i] + 0 << ' ';
    return 0;
}



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
