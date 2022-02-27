#include <iostream>
using namespace std;

int N;
double ans;
double arr[10001][2];

double ccw(int idx)
{
	double a, b;
	double x1 = arr[0][0];
	double x2 = arr[idx][0];
	double x3 = arr[idx + 1][0];
	double y1 = arr[0][1];
	double y2 = arr[idx][1];
	double y3 = arr[idx + 1][1];

	a = x1 * y2 + x2 * y3 + x3 * y1;
	b = x2 * y1 + x3 * y2 + x1 * y3;

	return ((a - b) * 0.5);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 0; idx < N; ++idx)
		cin >> arr[idx][0] >> arr[idx][1];
	for (int idx = 0; idx < N - 1; idx++)
		ans += ccw(idx);
	cout << fixed;
	cout.precision(1);
	cout << abs(ans) << '\n';
}
