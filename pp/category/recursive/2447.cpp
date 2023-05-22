#include <iostream>
using namespace std;
#define ll long long

int N;

void recur(int row, int col, int N)
{
	if (!N)
		cout << '*';
	else 
	{
		if (((row / N) % 3 == 1) && ((col / N) % 3 == 1))
			cout << ' ';
		else
			recur(row, col, N / 3);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 0; idx < N; ++idx)
	{
		for (int jdx = 0; jdx < N; ++jdx)
			recur(idx, jdx, N);
		cout << '\n';
	}
}
