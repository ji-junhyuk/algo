#include <bits/stdc++.h>
using namespace std;

bool comp(pair <int, int>a, pair<int, int> b){
    if(a.second != b.second){
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}
 
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<pair<int, int>> a(N);
	for (int i = 0; i < N; i++) 
		cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), comp);
	int beforetime = 0;
   	int cnt = 0;
	for (int i = 0; i < N; i++) 
	{
		if (beforetime <= a[i].first)
		{
			beforetime = a[i].second;
			cnt++;
		}
	}
	cout << cnt << '\n';
}
