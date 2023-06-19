#include <iostream>
using namespace std;

int N, M, T;
int disc[51][51];

void show()
{
	cout << '\n';
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << disc[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void spin(const int& identity, const int& rotate)
{
	int temp[51] = {};
	for (int i = 0; i < M; ++i) {
		temp[i] = disc[identity][i];
	}
	int start = rotate;
	int idx = 0;
	for (int i = start; i < M; ++i) {
		disc[identity][i] = temp[idx++];
	}
	for (int i = 0; i < start; ++i) {
		disc[identity][i] = temp[idx++];
	}
}

bool delete_same_number(int& sum, int& cnt)
{
	bool is_checked[51][51] = {};
	bool has_same_number = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (i != N - 1 && disc[i][j] != -1 && disc[i][j] == disc[i + 1][j]) {
				has_same_number = true;
				is_checked[i][j] = 1;
				is_checked[i + 1][j] = 1;
			}
			if (disc[i][j] != -1 && disc[i][j] == disc[i][(j + 1) % M]) {
				has_same_number = true;
				is_checked[i][j] = 1;
				is_checked[i][(j + 1) % M] = 1;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (is_checked[i][j]) {
				sum -= disc[i][j];
				cnt -= 1;
				disc[i][j] = -1;
			}
		}
	}
	if (has_same_number)
		return true;
	return false;
}

void apply_average(int& sum, int& cnt)
{
	if (cnt == 0) {
		sum = 0;
		return ;
	}
	double average = (double)sum / cnt;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (disc[i][j] != -1 && disc[i][j] < average) {
				++disc[i][j];
				++sum;
			}
			else if (disc[i][j] != -1 && disc[i][j] > average) {
				--disc[i][j];
				--sum;
			}
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> disc[i][j];
			sum += disc[i][j];
			++cnt;
		}
	}
	for (int i = 0; i < T; ++i) {
		int identity, dir, rotate;
		cin >> identity >> dir >> rotate;
		for (int j = identity; j <= N; j += identity) {
			if (dir == 0)
				spin(j - 1, rotate % M);
			else
				spin(j - 1, M - rotate % M);
		}
		bool is_exist_same_number = delete_same_number(sum, cnt);
		if (!is_exist_same_number)
			apply_average(sum, cnt);
	}
	cout << sum << '\n';
}
