
int fibo(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}

//int memo[100000000];
//int fibo(int n)
//{
//	count++;
//	if (n == 0)
//		return 0;
//	else if (n == 1)
//		return 1;
//	else
//	{
//		if (memo[n] != 0)
//			return memo[n];
//		memo[n] = fibo(n - 1) + fibo(n - 2);
//		return memo[n];
//	}
//}

//int memo[100000000];
//int fibo(int n)
//{
//	count++;
//	memo[0] = 0;
//	memo[1] = 1;
//	int i = 1;
//	while (++i <= n)
//		memo[i] = memo[i - 1] + memo[i - 2];
//	return memo[--i];
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
long long cnt;
int fibo3(int n, int r[])
{
	cnt++;
    if(n <= 0)
        return 0;
    else if(n == 1)
        return r[n] = 1;
    else if(r[n] > 0)
        return r[n];
    else
        return r[n] = fibo3(n - 1, r) + fibo3(n - 2, r);
}

int r[1000000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << fibo3(n, r) << '\n';
	cout << "count: " << cnt;
}

//#include <bits/stdc++.h>
//using namespace std;
//
//int arr[100000];
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	
//	int n;
//	int idx;
//
//	arr[0] = 0;
//	arr[1] = 1;
//	cin >> n;
//	idx = 1;
//	while (++idx <= n)
//		arr[idx] = arr[idx - 1] + arr[idx - 2];
//	idx = -1;
//	cout << arr[n - 1] << ' ' << '\n'; // n번째 값 구하기
//	while (++idx < n)
//		cout << arr[idx] << ' '; // n번째까지 피보나치 수열 구하기
//}
