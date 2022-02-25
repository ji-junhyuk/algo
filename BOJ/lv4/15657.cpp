#include <iostream>
#include <vector>
#include <algorithm>
# define MAX 8

using namespace std;

int N, M;
int arr[MAX];
int ans[MAX];
bool visited[MAX][MAX];
 
void print() 
{
    for (int idx = 0; idx < M; idx++) 
		cout << ans[idx] << " ";
    cout << "\n";
}
 
void dfs(int cnt) 
{
    if (cnt == M) 
	{
        print();
        return;
    }
    for (int idx = 0; idx < N; idx++) 
	{
        if (visited[cnt][idx] || visited[idx][cnt]) 
			continue;
        visited[cnt][idx] = true;
        visited[idx][cnt] = true;
		ans[cnt] = arr[idx];
		if (ans[cnt - 1] <= ans[cnt])
       		dfs(cnt + 1);
        visited[cnt][idx] = false;
        visited[idx][cnt] = false;
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
