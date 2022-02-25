#include <iostream>
#include <vector>
#include <algorithm>
# define MAX 8

using namespace std;

int N, M;
int arr[MAX];
int ans[MAX];
bool visited[MAX];
 
void print() 
{
    for (int idx = 0; idx < M; idx++) 
        cout << ans[idx] << " ";
    cout << "\n";
}
 
void dfs(int index) 
{
    if (index == M) 
	{
        print();
        return;
    }
    for (int idx = 0; idx < N; idx++) 
	{
        if (visited[idx]) continue;
		ans[index] = arr[idx];
        visited[idx] = true;
        dfs(index + 1);
        visited[idx] = false;
    }
}
 
int main() 
{
    cin >> N >> M;
    for (int idx = 0; idx < N; idx++) 
		cin >> arr[idx];
	sort(arr, arr + N);
    dfs(0);
    return 0;
}
