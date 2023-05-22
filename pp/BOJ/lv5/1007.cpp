#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
 
int T, N;
double result;
bool visited[21];
vector<pair<int, int>> vec_i_coord;

double find_sum()
{
    pair<int, int> vec = {0, 0};
    for (int idx = 0; idx < N; idx++)
	{
        if (visited[idx])
		{
            vec.first -= vec_i_coord[idx].first;
            vec.second -= vec_i_coord[idx].second;
        }
        else
		{
            vec.first += vec_i_coord[idx].first;
            vec.second += vec_i_coord[idx].second;
        }
    }
    return sqrt(pow(vec.first, 2) + pow(vec.second, 2));
}
 
void dfs(int now, int cnt)
{
    if (cnt == N / 2)
	{
        result = min(result, find_sum());
        return ;
    } 
    for (int idx = now; idx < N; ++idx)
	{
        visited[idx] = true;
        dfs(idx + 1, cnt + 1);
        visited[idx] = false;
    }
}
 
int main()
{
    cin >> T;
    while (T--)
	{
        memset(visited, 0, sizeof(visited));
        vec_i_coord.clear();
        result = INT_MAX;
		cin >> N;
		for (int idx = 0; idx < N; ++idx)
		{
			int a, b;
			cin >> a >> b;
			vec_i_coord.push_back({a, b});
		}
        dfs(0, 0);
		cout << fixed;
		cout.precision(12);
		cout << result << '\n';
    }
    return 0;
}
