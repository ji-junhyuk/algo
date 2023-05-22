#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>

#define MAX 200000

int dat[2 * MAX + 1];
int head = MAX, tail = MAX;
using namespace std;

int N;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		string op;
		cin >> op;
		if (op == "push_front")
		{
			int num;
			cin >> num;
			dat[--head] = num;
		}
		else if (op == "push_back")
		{
			int num;
			cin >> num;
			dat[tail++] = num;
		}
		else if (op == "pop_front")
		{
			if (tail - head == 0)
				cout << "-1\n";
			else
			{
				cout << dat[head] << '\n';
				++head;
			}
		}
		else if (op == "pop_back")
		{
			if (tail - head == 0)
				cout << "-1\n";
			else
			{
				cout << dat[tail - 1] << '\n';
				--tail;
			}
			
		}
		else if (op == "size")
		{
			cout << tail - head << '\n';
		}
		else if (op == "empty")
		{
			cout << (tail - head == 0) << '\n';
		}
		else if (op == "front")
		{
			if (tail - head == 0)
				cout << "-1\n";
			else
				cout << dat[head] << '\n';
		}
		else if (op == "back")
		{
			if (tail - head == 0)
				cout << "-1\n";
			else
				cout << dat[tail - 1] << '\n';
		}
	}
}
