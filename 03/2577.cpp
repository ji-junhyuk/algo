#include <bits/stdc++.h>
using namespace std;

int number[10];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    int a;
    int b;
    int c;
    int result;
    int i;

	cin >> a >> b >> c;
	result = a * b * c;
    if (result == 0)
        number[result]++;
    while (result)
    {
        number[result % 10]++;
        result /= 10;
    }
    i = -1;
    while (++i < 10)
        cout << number[i] << '\n';
    return 0;
}
