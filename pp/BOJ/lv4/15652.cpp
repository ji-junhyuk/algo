#include <iostream>
#include <vector>
#define MAX 8
 
using namespace std;
 
int N, M;
int arr[MAX];
vector<int> v;  
bool visited[MAX][MAX];
int cnt;
 
void print() 
{
    for (int idx = 0; idx < v.size(); idx++)
        cout << v[idx] << ' ';
    cout << '\n';
}
 
void dfs(int cnt, int value)
{
    if (cnt == M) 
	{
        print();
        return;
    }
 
    for (int idx = value; idx < N; idx++) 
	{
        if (visited[cnt][idx]) 
			continue;
        visited[cnt][idx] = true;
        v.push_back(arr[idx]);
        dfs(cnt + 1, arr[idx] - 1);
        visited[cnt][idx] = false;
        v.pop_back();
    }
}
 
int main(void) 
{
    cin >> N >> M;
 
    for (int idx = 0; idx < N; idx++) 
        arr[idx] = idx + 1;
    dfs(0, 0);
	return 0;
}
