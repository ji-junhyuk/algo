#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, M;

int selected[8];
bool is_selected[8];
vector<int> V;

void	bt(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i) 
		{
			cout << selected[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	int start = 0;
	if (depth)
		start = selected[depth - 1];
	for (int i = 0; i < V.size(); ++i) 
	{
		if (!is_selected[i] && V[i] != start)
		{
			is_selected[i] = 1;
			selected[depth] = V[i];
			bt(depth + 1);
			is_selected[i] = 0;
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		int num; 
		cin >> num;
		V.push_back(num);
	}
	sort(V.begin(), V.end());
//	V.resize(unique(V.begin(), V.end()) - V.begin());
	bt(0);
}
