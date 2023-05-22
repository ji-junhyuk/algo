#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

/*
 * rev라면 reverse()로 바꿀 수 있따.
 */
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		string cmd;
		cin >> cmd;
		int count;
		cin >> count;
		string numbers;
		cin >> numbers;
		int number = 0;
		deque<int> Q;
		int error = 0;
		int first = 1;
		for (int i = 1; i < numbers.size(); ++i) 
		{
			if (isdigit(numbers[i]))
			{
				number *= 10;
				number += numbers[i] - '0';
				++first;
			}
			else
			{
				if (first == 1 && count != 0)
					error = 1;
				if (first == 1 && count == 0)
					break ;
				Q.push_back(number);
				number = 0;
			}
		}
		int pure = 1;
		for (int i = 0; i < cmd.size(); ++i) 
		{
			if (cmd[i] == 'R')
			{
				pure *= -1;
			}
			else
			{
				if (Q.size() == 0)
				{
					error = 1;
					break ;
				}
				if (pure == 1)
				{
					Q.pop_front();
				}
				else
				{
					Q.pop_back();
				}
			}
		}
		if (error)
		{
			cout << "error" << '\n';
		}
		else
		{
			if (pure == 1)
			{
				cout << "[";
				while (!Q.empty())
				{
					cout << Q.front();
					Q.pop_front();
					if (Q.size() != 0)
						cout << ",";
				}
				cout << "]" << '\n';
				
			}
			else
			{
				cout << "[";
				while (!Q.empty())
				{
					cout << Q.back();
					Q.pop_back();
					if (Q.size() != 0)
						cout << ",";
				}
				cout << "]" << '\n';
			}
		}
	}

}
