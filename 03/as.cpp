#include <bits/stdc++.h>
using namespace std;

int a[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    while (N)
    {
        a[N % 10]++;
        N /= 10;
    }
    a[6] = ((a[6] + a[9] + 1) / 2);
    
    int Max = 1;
    for (int i = 0; i < 9; i++)
    {
        if (a[i] > Max)
            Max = a[i];
    }
    cout << Max;
}
