#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

#define MAX 10001
int dat[MAX];
int pos = 0;

void push(int x)
{
	dat[pos++] = x;
}

void top()
{
	if (pos == 0)
		cout << -1;
	else
		cout << dat[pos - 1];
	cout << '\n';
}

void pop()
{
	if (pos > 0)
	{
		cout << dat[pos - 1];
		pos--;
	}
	else 
		cout << -1;
	cout << '\n';
}

void size()
{
	cout << pos;
	cout << '\n';
}

void empty()
{
	if (pos == 0)
		cout << 1;
	else
		cout << 0;
	cout << '\n';
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	while (N--)
	{
		string op;
		cin >> op;
		if (op == "push")
		{
			int x;
			cin >> x;
			push(x);
		}
		else if (op == "top")
		{
			top();
		}
		else if (op == "pop")
		{
			pop();
		}
		else if (op == "size")
		{
			size();
		}
		else if (op == "empty")
		{
			empty();
		}
	}
}
