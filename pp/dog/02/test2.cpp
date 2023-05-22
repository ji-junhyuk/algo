#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int	main(void)
{
	char a[10];
	printf("input : ");
	scanf("%s", a);
	string s(a);
	printf("a is %s\n", a);
	printf("a is %s\n", s.c_str());
}
