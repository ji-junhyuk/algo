#include <bits/stdc++.h>
using namespace std;

/*
   첫줄은 0으로.
   비교하는 위치의 문자가 서로 
   같으면 (현재위치값: 왼쪽 대각선 값 + 1)
   다르면 (현재위치값: max(왼쪽 값, 위쪽 값)
*/
char s1[1002];
char s2[1002];
int dp[1001][1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> (char *)(s1 + 1);
	cin >> (char *)(s2 + 1);
	int idx;
	int jdx;


	for (idx = 1; s1[idx]; idx++)
		for (jdx = 1; s2[jdx]; jdx++)
			dp[idx][jdx] = max({dp[idx][jdx - 1], dp[idx - 1][jdx],
					dp[idx - 1][jdx - 1] + (s1[idx] == s2[jdx])});
	cout << dp[idx - 1][jdx - 1];
}
