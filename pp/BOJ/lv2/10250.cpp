#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	int H, W, N;
	int result;

	cin >> T;
	while (T--)
	{
		cin >> H >> W >> N;

		if (N % H == 0)
			result = H * 100 + (N / H);
		else
			result = N % H * 100 + (N / H) + 1;
		cout << result << '\n';
	}
}
