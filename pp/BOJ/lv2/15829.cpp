#include <bits/stdc++.h>
using namespace std;

// 문자열 총 길이가 50이므로 31^50을 하면 수가 너무 커서 오류
// 해시 함수의 정의에서 유한한 범위의 출력을 가져야 한다고 했으니까 적당히 큰 수 M으로 나눠주자.
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long result;
	char alpha[51];
	int L;
	int index;

	index = 1;
	result = 0;
	long long pow = 1;
	cin >> L;
	cin >> alpha;
	for (int idx = 0; alpha[idx]; idx++)
	{
		result += (alpha[idx] - 'a' + 1) * pow;
		result %= 1234567891;
		pow *= 31;
		pow %= 1234567891;
	}
	cout << result;
}
