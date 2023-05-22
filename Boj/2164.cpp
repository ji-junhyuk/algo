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

	int N;
	cin >> N;
	queue<int> card;
	for (int i = 1; i <= N; ++i) 
	{
		card.push(i);
	}
	while (card.size() != 1)
	{
		card.pop();
		int top = card.front();
		card.pop();
		card.push(top);
	}
	cout << card.front();
}
