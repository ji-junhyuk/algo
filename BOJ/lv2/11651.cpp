#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second < b.second)
	   	return true;
	else if (a.second == b.second)
		if (a.first < b.first)
			return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
    
	cin >> N;
    vector<pair<int, int>> v(N);
   
   	for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; i++)
        cout << v[i].first << ' ' << v[i].second<< '\n';
}
