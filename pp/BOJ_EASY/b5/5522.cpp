#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 5;
    int sum = 0;
    while (N--)
    {
	   int temp;
	   cin >> temp;
	   sum += temp;
    }
    cout << sum;
}
