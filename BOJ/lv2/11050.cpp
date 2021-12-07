#include <bits/stdc++.h>
using namespace std;

//이항계수란 n개의 원소에서 k개의 원소를 뽑아내는 경우의 수
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;

	cin >> N >> K;
	int result1;
	int result2;
	int result3;

	int temp;
	int fin;

	temp = N;
	result1 = 1;
	while (temp)
		result1 *= temp--;
 	result2 = 1;
	temp = N;
 	int n_k = temp - K;
 	while (n_k)
 		result2 *= n_k--;
 	result3 = 1;
 	while (K)
 		result3 *= K--;
	fin = result1 / (result2 * result3);
	cout << fin;
}
