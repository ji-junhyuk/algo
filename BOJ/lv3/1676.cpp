#include <bits/stdc++.h>
using namespace std;

/*
   뒤에 0이 나오는 경우 2 * 5;
   소인수 분해 했을 때 min(2의 개수, 5의 개수)
*/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int five_number = 0;

	cin >> N;
//	int result = 1;
//	int k = N;
//	while (k)
//		result *= k--;
//	cout << result << '\n';
	for (int idx = 5; idx <= N; idx *= 5)
		five_number += N / idx;
	cout << five_number;
}
