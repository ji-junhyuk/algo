#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, K;
int chess[13][13];

vector<pair<int, int>> knight[13][13]; // identity, dir
vector<pair<int, int>> pos; // location 
int dy[] = {0x7ffffff, 0, 0, -1, 1};
int dx[] = {0x7ffffff, 1, -1, 0, 0};

void show()
{
	cout << "show, size\n";
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cout << knight[i][j].size() << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

bool move_white(int& y, int& x, int& dir, int& ny, int& nx, int &index, int& size)
{
	for (int i = index; i < size; ++i) {
		int identity, dir;
		tie(identity, dir) = knight[y][x][index];
		knight[y][x].erase(knight[y][x].begin() + index);
		knight[ny][nx].push_back({identity, dir});
		pos[identity] = {ny, nx};
	}
	if (knight[ny][nx].size() >= 4)
			return true;
	return false;
}

bool move_red(int& y, int& x, int& dir, int& ny, int& nx, int &index, int& size)
{
	for (int i = size - 1; i >= index; --i) {
		int identity, dir;
		tie(identity, dir) = knight[y][x][i];
		knight[y][x].erase(knight[y][x].end() - 1);
		knight[ny][nx].push_back({identity, dir});
		pos[identity] = {ny, nx};
	}
	if (knight[ny][nx].size() >= 4)
		return true;
	return false;
}

bool move_blue(int& y, int& x, int& dir, int& ny, int& nx, int &index, int &size)
{
	if (dir == 1 || dir == 2)
		dir = 3 - dir;
	else if (dir == 3 || dir == 4)
		dir = 7 - dir;
	knight[y][x][index].second = dir;
	int ny2 = y + dy[dir];
	int nx2 = x + dx[dir];
	if (!(ny2 < 1 || ny2 > N || nx2 < 1 || nx2 > N)) {
		if (chess[ny2][nx2] == 0) {
			if (move_white(y, x, dir, ny2, nx2, index, size))
				return true;
		}
		else if (chess[ny2][nx2] == 1) {
			if (move_red(y, x, dir, ny2, nx2, index, size))
				return true;
		}
	}
	return false;
}

bool move_knight(int turn) // turn = identity
{
	int y, x, size, dir;
	int index = -1;
	tie(y, x) = pos[turn]; 
	size = knight[y][x].size();
	for (int i = 0; i < size; ++i) 
	{
		if (turn == knight[y][x][i].first)
		{
			index = i;
			break ;
		}
	}
	dir = knight[y][x][index].second;
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if ((ny < 1 || ny > N || nx < 1 || nx > N)) {
		if (move_blue(y, x, dir, ny, nx, index, size))
			return true;
	}
	else if (chess[ny][nx] == 0) {
		if (move_white(y, x, dir, ny, nx, index, size))
			return true;
	}
	else if (chess[ny][nx] == 1) {
		if (move_red(y, x, dir, ny, nx, index, size))
			return true;
	}
	else if (chess[ny][nx] == 2) {
		if (move_blue(y, x, dir, ny, nx, index, size))
			return true;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> chess[i][j];
		}
	}
	pos.push_back({0x7ffffff, 0x7ffffff}); // dummy
	for (int i = 1; i <= K; ++i) {
		int y, x, dir;
		cin >> y >> x >> dir;
		knight[y][x].push_back({i, dir});
		pos.push_back({y, x});
	}
	bool game_end = false;
	for (int time = 1; time <= 1000; ++time) {
		for (int i = 1; i <= K; ++i) {
			game_end = move_knight(i);
			if (game_end) {
				cout << time << '\n';
				return 0;
			}
		}
	}
	cout << -1 << '\n';
}
