#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

#define MAX 100000
int dat[MAX];
int head, tail;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		string op;
		cin >> op;
		if (op == "push")
		{
			int x;
			cin >> x;
			dat[tail++] = x;
		}
		else if (op == "pop")
		{
			if (tail - head == 0)
				cout << "-1\n";
			else
			{
				cout << dat[head] << '\n';
				++head;
			}
		}
		else if (op == "size")
		{
			cout << tail - head << '\n';
		}
		else if (op == "empty")
		{
			if (tail - head == 0)
				cout << "1";
			else
				cout << "0";
			cout << '\n';
		}
		else if (op == "front")
		{
			if (tail - head == 0)
				cout << "-1";
			else
				cout << dat[head];
			cout << '\n';
		}
		else // back
		{
			if (tail - head == 0)
				cout << "-1";
			else
				cout << dat[tail - 1];
			cout << '\n';
		}
	}
}
