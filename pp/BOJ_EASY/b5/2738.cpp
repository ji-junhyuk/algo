#include <iostream>
using namespace std;

int N, M;
int arr[101][101];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int idx = 0; idx < N; ++idx)
		for (int jdx = 0; jdx < M; ++jdx)
			cin >> arr[idx][jdx];
	for (int idx = 0; idx < N; ++idx)
	{
		for (int jdx = 0; jdx < M; ++jdx)
		{
			int temp;
			cin >> temp;
			arr[idx][jdx] += temp;
		}
	}
	for (int idx = 0; idx < N; ++idx)
	{
		for (int jdx = 0; jdx < M; ++jdx)
			cout << arr[idx][jdx] << ' ';
		cout << '\n';
	}
}
