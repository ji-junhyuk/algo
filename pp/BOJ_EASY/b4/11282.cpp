#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;


int main(void)
{
	int N;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	cin >> N;
	N += 3071;
	S.push_back(N / 4096 + 234); //초성 ㄱ은 234부터 시작.
	S.push_back(N / 64 % 64 + 128); //첫바이트 제외 128 ~ 191 범위
	S.push_back(N % 64 + 128);
	cout << S;
}
