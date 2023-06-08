#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

/*
 * hit_order[3] = 3; 이런식으로 처리하는 실수
 */
int N;
int result[50][9];
int hit_order[9];
int ans;

void play()
{
	int score = 0;
	int idx = 0;
	for (int inning = 0; inning < N; ++inning) 
	{
		bool base[4] = {};
		int out = 0;
		while (out < 3)
		{
			base[0] = true;
			int hit_result = result[inning][hit_order[idx++]];
			if (idx == 9)
				idx = 0;
			if (!hit_result)
			{
				++out; continue;
			}
			for (int i = 3; i >= 0; --i) 
			{
				if (!base[i])
					continue ;
				if (i + hit_result >= 4)
					++score;
				else 
					base[i + hit_result] = true;
				base[i] = false;
			}
		}
	}
	cout << "score: " << score << '\n';
	ans = max(ans, score);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < 9; ++j) 
		{
			cin >> result[i][j];
		}
	}
	int order[] = {1, 2, 3, 4, 5, 6, 7, 8};
	hit_order[3] = 0;
	do {
		for (int i = 0; i < 9; ++i) 
		{
			if (i < 3)
				hit_order[i] = order[i];
			if (i > 3)
				hit_order[i] = order[i - 1];
		}
		play();
	} while (next_permutation(order, order + 8));
	cout << ans << '\n';
}
