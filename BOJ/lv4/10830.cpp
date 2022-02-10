#include <bits/stdc++.h>
using namespace std;

long long N, B;
long long A[5][5];
long long temp[5][5];
long long ans[5][5];

void	multiply_matrix(long long a[5][5], long long b[5][5])
{
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
		{
			temp[idx][jdx] = 0;
			for (int kdx = 0; kdx < N; kdx++)
				temp[idx][jdx] += (a[idx][kdx] * b[kdx][jdx]);
			temp[idx][jdx] %= 1000;
		}
	}
	for (int idx = 0; idx < N; idx++)
		for (int jdx = 0; jdx < N; jdx++)
			a[idx][jdx] = temp[idx][jdx];
}

int main(void)
{
	cin >> N >> B;

	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
			cin >> A[idx][jdx];
		ans[idx][idx] = 1;
	}
	while (B)
	{
		if (B % 2)
			multiply_matrix(ans, A);
		multiply_matrix(A, A);
		B /= 2;
	}
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
			cout << ans[idx][jdx] << " ";
		cout << '\n';
	}
	return (0);
}
