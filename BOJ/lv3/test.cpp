#include <bits/stdc++.h>
using namespace std;

int valid[1000001];
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
				valid[idx] = 1;
			}
			else
			{
//				if (idx == 2)
//				{
//					cout << "max" << '\n';
//					while (!max_heap.empty())
//					{
//						cout << max_heap.top().first << ' ' << max_heap.top().second << '\n';
//					max_heap.pop();
//					}
//					cout << "min" << '\n';
//					while (!min_heap.empty())
//					{
//						cout << min_heap.top().first << ' ' << min_heap.top().second << '\n';
//					min_heap.pop();
//					}
//					cout << "end\n";
//				}
				if (num > 0)
				{
					while (!max_heap.empty() && !valid[max_heap.top().second])
						max_heap.pop();
					if (!max_heap.empty())
					{
						valid[max_heap.top().second] = 0;
						max_heap.pop();
					}
				}
				else
				{
					while (!min_heap.empty() && !valid[min_heap.top().second])
						min_heap.pop();
					if (!min_heap.empty())
					{
						valid[min_heap.top().second] = false;
						min_heap.pop();
					}
				}
			}
			while (!max_heap.empty() && !valid[max_heap.top().second])
				max_heap.pop();
			while (!min_heap.empty() && !valid[min_heap.top().second])
				min_heap.pop();
		}
		if (max_heap.empty())
			cout << "EMPTY\n";
		else
			cout << max_heap.top().first << ' ' << min_heap.top().first << '\n';
	}
}
