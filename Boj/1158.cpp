#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;
#define MAX 5001
int dat[MAX];
int pre[MAX];
int nxt[MAX];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	nxt[0] = 1;
	for (int i = 1; i <= N; ++i) 
	{
		pre[i] = (i == 1) ? N : i - 1;
		nxt[i] = (i == N) ? 1 : i + 1;
		dat[i] = i;
	}
	int cursor = 0;
	cout << "<";
	int gap = 0;
	while (N--)
	{
		for (int i = 0; i < K - gap; ++i) 
		{
			cursor = nxt[cursor];
		}
		cout << dat[cursor];
		if (N != 0)
			cout << ", ";
		nxt[pre[cursor]] = nxt[cursor];
		if (nxt[cursor] != -1)
			pre[nxt[cursor]] = pre[cursor];
		cursor = nxt[cursor];
		gap = 1;
	}
	cout << ">";
}
