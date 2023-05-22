#include <bits/stdc++.h>
using namespace std;

int flag[1000001]; 
int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, Q;
	cin >> T;
    
    while(T--)
	{
		cin >> Q;
        priority_queue<pair<int, int>> max_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
		for (int idx = 0; idx < Q; idx++)
		{
			char op;
			int num;
			cin >> op >> num;
			if (op == 'I')
			{
				max_heap.push({num, idx});
				min_heap.push({num, idx});
				flag[idx] = 1;
			}
			else
			{
				if (num > 0)
				{
					if (!max_heap.empty())
					{
						flag[max_heap.top().second] = 0;
						max_heap.pop();
					}
				}
				else
				{
					if (!min_heap.empty())
					{
						flag[min_heap.top().second] = false;
						min_heap.pop();
					}
				}
			}
			while (!max_heap.empty() && !flag[max_heap.top().second])
				max_heap.pop();
			while (!min_heap.empty() && !flag[min_heap.top().second])
				min_heap.pop();
		}
		if (max_heap.empty())
			cout << "EMPTY\n";
		else
			cout << max_heap.top().first << ' ' << min_heap.top().first << '\n';
	}
}
