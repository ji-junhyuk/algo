#include <iostream>
#include <vector>
#include <algorithm>
# define MAX 8

using namespace std;

int N, M;
int arr[MAX];
int ans[MAX];
 
void print() 
{
    for (int idx = 0; idx < M; idx++) 
		cout << ans[idx] << " ";
    cout << "\n";
}
 
void dfs(int cnt, int index) 
{
    if (cnt == M) 
	{
        print();
        return;
    }
	bool repeated[10001] = {false};
    for (int idx = index; idx < N; idx++) 
	{
		if (repeated[arr[idx]])
			continue;
		repeated[arr[idx]] = true;
		ans[cnt] = arr[idx];
		dfs(cnt + 1, idx);
    }
}
 
int main() 
{
    cin >> N >> M;
    for (int idx = 0; idx < N; idx++) 
		cin >> arr[idx];
	sort(arr, arr + N);
    dfs(0, 0);
    return 0;
}
