#include <iostream>
#define MAX 8
 
using namespace std;
 
int arr[MAX];
bool visited[MAX];
int N, M;
 
void print_arr() 
{
    for (int idx = 0; idx < N; idx++)
        if (visited[idx])
            cout << arr[idx] << " ";
    cout << '\n';
}
 
void dfs(int cnt, int index) 
{
    if (cnt == M) 
	{
        print_arr();
        return;
    }
    for (int idx = index; idx < N; idx++) 
	{
        if (visited[idx] == true) 
			continue;
        visited[idx] = true;
        dfs(cnt + 1, idx + 1);
        visited[idx] = false;
    }
}
 
int main(void) 
{
    cin >> N >> M;
    for (int idx = 0; idx < N; idx++) 
	{
        arr[idx] = idx + 1;
        visited[idx] = false;
    }
    dfs(0, 0);
}
