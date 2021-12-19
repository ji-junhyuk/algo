#include <bits/stdc++.h>
using namespace std;

int len_line[10001];
int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int N;
        int K;
        int max;
        unsigned int left;
        unsigned int right;
        unsigned int center;
        int max_len;
        int share;

        cin >> K >> N;
        max = 1;
        for (int idx = 0; idx < K; idx++)
        {
                cin >> len_line[idx];
                if (max < len_line[idx])
                        max = len_line[idx];
        }
        left = 1;
        right = max;
        max_len = 1;
        while (left <= right)
        {
                share = 0;
                center = (left + right) / 2;
                for (int idx = 0; idx < K; idx++)
                        share += len_line[idx] / center;
                if (share >= N)
                {
                        left = center + 1;
                        if (max_len < center)
                                max_len = center;
                }
                else
                        right = center - 1;
        }
        cout << max_len << '\n';
}
