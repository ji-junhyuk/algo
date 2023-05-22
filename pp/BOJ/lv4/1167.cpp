#include <iostream> 
#include <bits/stdc++.h>
#define MAX 100001
/*
   특정 X에서 거리가 가장 먼 노드가 트리의 지름을 만드는 2개의 노드 중 하나
   가장 먼 노드에서 다시 DFS실행하면 트리의 지름값.
*/
using namespace std; 

int V; 
int N, NV, D; 
vector<pair<int, int>> vec[MAX]; 
bool visited[MAX]; 
int result; 
int leaf; 

void DFS(int cur, int dist) 
{ 
    if (visited[cur]) 
		return;
    visited[cur] = 1;  
    if (dist > result)
	{ 
        result = dist; 
        leaf = cur; 
    }

    for (int i = 0; i < vec[cur].size(); i++) 
	{
        int dx = vec[cur][i].first; 
        int dy = vec[cur][i].second; 
        DFS(dx, dist + dy); 
    }   
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> V; 
    for (int i = 0 ; i < V; i++) 
	{
        cin >> N; 
        while (1) 
		{ 
            cin >> NV; 
            if (NV == -1) 
				break;  
            cin >> D;
            vec[N].push_back(make_pair(NV, D)); 
        }
    }
    memset(visited, 0, sizeof(visited)); 
    DFS(1, 0); 
    memset(visited, 0, sizeof(visited));
    DFS(leaf, 0); 
    cout << result; 
}
