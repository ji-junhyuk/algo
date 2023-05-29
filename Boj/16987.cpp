#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N;
int ans = 0;
tuple<int, int, bool>egg[8]; // durability, weight, broken
bool is_selected[8];

void bt(int depth)
{
	if (depth == N)
	{
		int cnt = 0;
		for (int i = 0; i < N; ++i) 
		{
			if (get<2>(egg[i]) == true)
				++cnt;
		}
		ans = max(ans, cnt);
		return ;
	}
	if (get<0>(egg[depth]) <= 0)
	{
		bt(depth + 1);
		return ;
	}
	for (int i = 0; i < N; ++i) 
	{
		int a_durability = get<0>(egg[depth]);
		int a_weight = get<1>(egg[depth]);
		bool a_broken = get<2>(egg[depth]);
		int b_durability = get<0>(egg[i]);
		int b_weight = get<1>(egg[i]);
		bool b_broken = get<2>(egg[i]);
		if (i != depth && b_durability >= 1)
		{
			get<0>(egg[depth]) -= get<1>(egg[i]);
			if (get<0>(egg[depth]) <= 0)
				get<2>(egg[depth]) = true;
			get<0>(egg[i]) -= get<1>(egg[depth]);
			if (get<0>(egg[i]) <= 0)
				get<2>(egg[i]) = true;

			bt(depth + 1);
			get<0>(egg[depth]) += get<1>(egg[i]);
			get<0>(egg[i]) += get<1>(egg[depth]);
			if (get<0>(egg[depth]) >= 1)
				get<2>(egg[depth]) = false;
			if (get<0>(egg[i]) >= 1)
				get<2>(egg[i]) = false;
		}
	}
	if (depth == N - 1)
		bt(depth + 1);

}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		int a, b;
		cin >> a >> b;
		egg[i] = make_tuple(a, b, 0);
	}
	bt(0);
	cout << ans << '\n';
}
