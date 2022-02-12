#include <bits/stdc++.h>
 
using namespace std;
 
int N, M;
int chicken_num, ans;
int board[50][50];
int selected[13];
 
vector<pair<int, int>> house, chicken, v;
 
int Calculate_Distance()
{
    int Sum = 0;
    for (int idx = 0; idx < house.size(); idx++)
    {
        int x = house[idx].first;
        int y = house[idx].second;
        int d = INT_MAX;
 
        for (int jdx = 0; jdx < v.size(); jdx++)
        {
            int xx = v[jdx].first;
            int yy = v[jdx].second;
            int Dist = abs(xx - x) + abs(yy - y);
 
            d = min(d, Dist);
        }
        Sum = Sum + d;
    }
    return Sum;
}
 
void select_chicken(int index, int Cnt)
{
    if (Cnt == M)
    {
        ans = min(ans, Calculate_Distance());
        return;
    }
 
    for (int idx = index; idx < chicken_num; idx++)
    {
        if (selected[idx] == 1) 
			continue;
        selected[idx] = 1;
        v.push_back(chicken[idx]);
        select_chicken(idx, Cnt + 1);
        selected[idx] = 0;
        v.pop_back();
    }
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ans = INT_MAX;
    cin >> N >> M;
    for (int idx = 0; idx < N; idx++)
    {
        for (int jdx = 0; jdx < N; jdx++)
        {
            cin >> board[idx][jdx];
            if (board[idx][jdx] == 1) house.push_back(make_pair(idx, jdx));
            if (board[idx][jdx] == 2) chicken.push_back(make_pair(idx, jdx));
        }
    }
    chicken_num = chicken.size();
    select_chicken(0, 0);
    cout << ans;
 
    return 0;
}
