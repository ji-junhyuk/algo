#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
}

int memo[100000];
int func2(int n)
{
	printf("func call param %d\n", n);
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (memo[n] != 0)
		return memo[n];
	memo[n] = func2(n - 1) + func2(n - 2);
	return memo[n];
}

int func(int n)
{
	printf("func call param %d\n", n);
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return func(n - 1) + func(n - 2);
}
int fibo3(int n, int r[])
{
    if(n <= 0)
        return r[0];
    else if(n == 1)
        return r[n] = 1;
    else if(r[n] > 0)
        return r[n];
    else
        return r[n] = fibo3(n - 1, r) + fibo3(n - 2, r);
}

int r[10000];
int main(void)
{
	int n;
	cin >> n;
	printf("%d\n", fibo3(n, r));

//	int idx;
//	idx = -1;
//	while (++idx < 15)
//		printf("%d ", func2(idx));
	return (0);
}
