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

	deque<int> Q;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) 
		Q.push_back(i);

	int count = 0;
	for (int i = 0; i < M; ++i) 
	{
		int num;
		cin >> num;
		int idx = find(Q.begin(), Q.end(), num) - Q.begin();
		int size = Q.size();
		while (Q.front() != num)
		{
			if (idx <= size / 2)
			{
				int front = Q.front();
				Q.pop_front();
				Q.push_back(front);
			}
			else
			{
				int back = Q.back();
				Q.pop_back();
				Q.push_front(back);
			}
			++count;
		}
		Q.pop_front();
	}
	cout << count << '\n';
}
