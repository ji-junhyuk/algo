#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int a, b, c;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;
	int cnt = 0;
	if (a == b)
		++cnt;
	if (b == c)
		++cnt;
	if (a == c)
		++cnt;
	if (a == 60 && b == 60 && c == 60)
		cout << "Equilateral";
	else if (a + b + c == 180 && cnt == 1)
		cout << "Isosceles";
	else if (a + b + c == 180 && !cnt)
		cout << "Scalene";
	else if (a + b + c != 180)
		cout << "Error";
	
}
