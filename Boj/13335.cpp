#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int n, w, l;
int bridge[100];
int truck[1000];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> w >> l;
	for (int i = 0; i < n; ++i) 
	{
		cin >> truck[i];
		// 다리의 하중
	}
	int time = 0;
	for (int i = 0; i < n; ++i) 
	{
		int cur_weight = 0;
		for (int i = 0; i < w; ++i) 
		{
			cur_weight += bridge[i];
		}
		// 7 + 4 <=  10
		// 현재하중 + 트럭 한개 더한게 <= 최대 하중
		if (cur_weight + truck[i] <= l)
		{
			bridge[0] = truck[i];
		}
		else
		{
			while (1)
			{
				++time;
				for (int i = w; i >= 1; --i) 
				{
					bridge[i] = bridge[i - 1];
				}
				bridge[0] = 0;
				cur_weight = 0;
				for (int i = 0; i < w; ++i) 
				{
					cur_weight += bridge[i];
				}
//				cout << "cur_weight: " << cur_weight << '\n';
				if (cur_weight + truck[i] <= l)
				{
					bridge[0] = truck[i];
					break ;
				}
			}
		}
		++time;
		for (int i = w; i >= 1; --i) 
		{
			bridge[i] = bridge[i - 1];
		}
		bridge[0] = 0;
//		cout << "time: " << time << '\n';
//		for (int i = 0; i < w; ++i) 
//		{
//			cout << bridge[i] << ' ';
//		}
//		cout << '\n';
		// 8 5 3
		// bridge 7 0 
	}
	cout << time + w << '\n';

}
