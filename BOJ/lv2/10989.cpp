#include <bits/stdc++.h>
using namespace std;

int arr[10001];
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int N;

        cin >> N;
        while (N--)
        {
                int number;
                cin >> number;
                arr[number] += 1;
        }
        for (int idx = 1; idx < 10001; idx++)
                for (int jdx = 0; jdx < arr[idx]; jdx++)
                                cout << idx << '\n';
}
