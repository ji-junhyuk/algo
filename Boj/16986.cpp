#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
#include <map>
using namespace std;

/*
 * 처음에 문제가 말이 안된다고 생각했다.
 * N이 3일때, K가 4이상도 올 수 있다는 생각이 들어서,
 * 모든 손동작을 다르게 내어 우승할 수 있다면이라는 말을 1 2 1 2 
 * 이것도 가능하다고 생각.
 * 그럼 시간복잡도가 N이 9일때 거의 9^9가까운 값이니...
 *
 * 인덱스 접근이며 0 또는 1 시작인지 꼼꼼하게 신경 쓸 부분이 많다
 */
int N, K;
int win_table[10][10];
int selected[20];
int pattern[3][20];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			cin >> win_table[i][j];
		}
	}
	for (int i = 0; i < 20; ++i) 
	{
		cin >> pattern[1][i];
	}
	for (int i = 0; i < 20; ++i) 
	{
		cin >> pattern[2][i];
	}
	for (int i = 0; i < N; ++i) 
	{
		pattern[0][i] = i + 1;
	}
	do {
		int left = 0, right = 1;
		int score[3] = {0, 0, 0};
		int index[3] = {0, 0, 0};
		while (1)
		{
			if (left > right)
				swap(left, right);
			if (left == 0 && index[0] >= N)
				break ;
			int sel1 = pattern[left][index[left]++];
			int sel2 = pattern[right][index[right]++];
			if (win_table[sel1][sel2] == 2) // sel1 win
			{
				score[left]++;
				if (score[left] >= K)
					break ;
				right = 3 - left - right;
			}
			else // sel2 win
			{
				score[right]++;
				if (score[right] >= K)
					break ;
				left = 3 - left - right; // sel2
			}
		}
		if (score[0] >= K)
		{
			cout << 1 << '\n';
			return (0);
		}
	} while (next_permutation(pattern[0], pattern[0] + N));
	cout << 0 << '\n';
}

