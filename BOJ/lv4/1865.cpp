#include <bits/stdc++.h>
#define MAX 501
#define INF INT_MAX
using namespace std;
 
int N, M, W;
int Dist[MAX];
string ans;
vector<pair<pair<int, int>, int>> v;
 
void bellManFord()
{
    Dist[1] = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int a = v[j].first.first;
            int b = v[j].first.second;
            int c = v[j].second;
 
            if (Dist[a] == INF) 
				continue;
            if (Dist[b] > Dist[a] + c)
			   	Dist[b] = Dist[a] + c;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        int a = v[i].first.first;
        int b = v[i].first.second;
        int c = v[i].second;
 
        if (Dist[a] == INF) 
			continue;
        if (Dist[b] > Dist[a] + c)
        {
            ans = "YES";
            return;
        }
    }
    ans = "NO";
}
 
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int Tc; 
	
	cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
		for (int i = 1; i < MAX; i++) 
			Dist[i] = INF;
		memset(Dist, -1, sizeof(Dist));
		v.clear();

		cin >> N >> M >> W;
		for (int idx = 0; idx < M; idx++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			v.push_back({{a,b}, c});
			v.push_back({{b,a}, c});
		}
		for (int idx = 0; idx < W; idx++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			v.push_back({{a,b}, -c});
		}
		bellManFord();
        cout << ans << '\n';
    }
}
