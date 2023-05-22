#include <iostream>
ss#include <cstring>

using namespace std;

char *max(char *a, char *b)
{
	for (int idx = 0; idx < strlen(a); ++idx)
	{
		if (a[idx] < b[idx])
			return b;
		if (a[idx] > b[idx])
			return a;
	}
	return a;
}

void	subtract(char *a, char *b)
{
	for (int idx = 0; idx < strlen(b); idx++)
	{
		a[idx] = a[idx] - b[idx] + '0';
		if (a[idx] < '0')
		{
			a[idx] += 10;
			a[idx - 1]--;
		}
	}
	for (int idx = strlen(b) - 1; idx >= 0; idx--)
	{
		if (a[idx] < '0')
		{
			a[idx] += 10;
			a[idx - 1]--;
		}
	}
}

void	devidesubtract(char *a, char *b, char *r, int index)
{
	r[index] = '0';

	while (a[index - 1] > '0' || max(a + index, b) == a + index)
	{
		subtract(a + index, b);
		++r[index];
	}
}

void devide(char *a, char *b, char *r)
{
	int index = 0;
	int digit = strlen(a) - strlen(b);

	while (index <= digit)
		devidesubtract(a, b, r, index++);
	r[index] = '\0';
}

int main(void)
{
	char a[1001];
	char b[1001];
	char r[1001];

	int ri = 0, ai = 0;
	cin >> a >> b;
	devide(a, b, r);

	while (r[ri] == '0')
		ri++;
	while (a[ai] == '0')
		ai++;
	if (a[ai] == '\0')
		ai--;
	if (r[ri] == '\0')
		ri--;
	cout << r + ri << '\n';
	cout << a + ai << '\n';
	return (0);
}
