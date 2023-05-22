#include <stdio.h>

int facto(int n)
{
	if (n == 0)
		return 1;
	else
		return n * facto(n - 1);
}

int main(void)
{
	printf("%d\n", facto(1));
	printf("%d\n", facto(2));
	printf("%d\n", facto(3));
	printf("%d\n", facto(4));
	printf("%d\n", facto(5));
	return (0);
}
