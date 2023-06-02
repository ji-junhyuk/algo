#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;


//1. 조합으로 치킨집 고르고,
//2. 모든 집 중에 하나의 집을 기준으로 모든 치킨집을 돌면서 최소거리를 구함. (절대값)
//3. 그렇게 하나의 조합에 대한 최소거리를 구함.
//4. 그렇게 다음 조합.
//5. 모든 조합을 거친 최소거리를 답으로 출력함.

int N, M;
int city[50][50];
vector<pair<int, int>> house;
vector<pair<int, int>> chic;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> city[i][j];
			if (city[i][j] == 1)
			{
				house.push_back({i, j});
			}
			else if (city[i][j] == 2)
			{
				chic.push_back({i, j});
			}
		}
	}
	bool selected[13] = {};
	int chic_size = chic.size();
//	cout << chic_size << '\n';
	fill(selected + M, selected + chic_size, 1);
// 5개 중에 2개라면 0 0 1 1 1
// 5개 중에 2개라면 1 1 1 1 1
//	for (int i = 0; i < 13; ++i) 
//	{
//		cout << selected[i] << ' ';
//	}
	// 0 0 0
//	cout << '\n';
	long ans = 0x7fffffff;//  도시의 치킨 거리 최소값
	do {
		long city_min_dist = 0;
		for (auto h : house)
		{
			long min_dist = 0x7fffffff; // 하나의 집과 치킨집 최소거리
			for (int i = 0; i < chic_size; ++i) 
			{
				if (!selected[i])
				{
					int hy = h.first;
					int hx = h.second;
					int cy = chic[i].first;
					int cx = chic[i].second;
					long dist = abs(hy - cy) + abs(hx - cx);
					min_dist = min(min_dist, dist);
//					cout << "dist:" << dist << ' ' << "min_dist: " << min_dist << '\n';
				}
			}
			city_min_dist += min_dist;
		}
		ans = min(ans, city_min_dist);
//		cout << '\n';

	} while (next_permutation(selected, selected + chic_size));
	cout << ans << '\n';
}

