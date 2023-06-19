#include <iostream>
using namespace std;

int board[33] = {
	0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38,
    13, 16, 19,
    22, 24,
    28, 27, 26, 25, 30, 35, 40, 0 
};
int pos[4] = {0, 0, 0, 0};
int nxt[33];
int dice[10];
int ans;

int move_knight(int depth, int identity) {
	int step = pos[identity];
	
	int move_count = dice[depth];
	if (step == 5 || step == 10 || step == 15) {
		if (step == 5)
			step += 15;
		if (step == 10)
			step += 13;
		if (step == 15)
			step += 10;
		--move_count;
	}
	for (int i = 0; i < move_count; ++i) {
		if (step == 32)
			break ;
		step = nxt[step];
	}
	return step;
}

bool can_move(int identity, int next_pos)
{
	if (next_pos == 32)
		return true;
	for (int i = 0; i < 4; ++i) {
		if (i == identity) continue ;
		if (pos[i] == next_pos)
			return false;
	}
	return true;
}

void bt(int depth, int score) {
	if (depth == 10) {
		ans = max(ans, score);
		return ;
	}
	for (int i = 0; i < 4; ++i) { 
		int cur_pos = pos[i];
		int next_pos = move_knight(depth, i);
		if (can_move(i, next_pos)) {
			pos[i] = next_pos;
			bt(depth + 1, score + board[next_pos]);
			pos[i] = cur_pos;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 32; ++i) {	
		nxt[i] = i + 1;
	}
	nxt[19] = 31;
	nxt[22] = 28;
	nxt[24] = 28;
	for (int i = 0; i < 10; ++i) {
		cin >> dice[i];
	}
	bt(0, 0);
	cout << ans << '\n';
}
