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

	int arr[26] = {};
	string word;

	cin >> word;
	for (int i = 0; i < word.size(); ++i) 
	{
		arr[word[i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i) 
	{
		cout << arr[i] << ' ';
	}
}
