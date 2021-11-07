#include <bits/stdc++.h>
using namespace std;

int arr[2000000];
int check[20000000];
int main(void)
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n;
        int x;
        int i;
        int j;
        int count;

        cin >> n;
        i = -1;
        while (++i < n)
                cin >> arr[i];
        cin >> x;
        count = 0;
        i = -1;
        while (++i < n)
        {
                check[arr[i]] = 1;
                if (x == arr[i])
                    count++;
                if (x - arr[i] >= 0)
                    if (check[x - arr[i]] == 1 && arr[i] != x - arr[i])
                            count++;
        }
        cout << count;
}
