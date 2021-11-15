#include <stdio.h>

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

int main(void)
{
	printf("%d\n", func(0));
	printf("%d\n", func(1));
	printf("%d\n", func(2));
	printf("%d\n", func(3));
	printf("%d\n", func(4));
	printf("%d\n", func2(0));
	printf("%d\n", func2(1));
	printf("%d\n", func2(2));
	printf("%d\n", func2(3));
	printf("%d\n", func2(4));
	int idx;
	idx = -1;
	while (++idx < 15)
		printf("%d ", func2(idx));
	return (0);
}
