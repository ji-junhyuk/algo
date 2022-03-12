#include <iostream>
#include <vector>
#include <algorithm>
# define MAX 1001
using namespace std;

long long T;
int n, m;
int i_a[MAX], i_b[MAX];
vector<long long> vec_a_sum, vec_b_sum;
long long ll_cnt;

void find_sum()
{
    for (int idx = 0; idx < n; ++idx)
	{
        int i_sum = 0;
        for (int jdx = idx; jdx < n; ++jdx)
		{
            i_sum += i_a[jdx];
			vec_a_sum.push_back(i_sum);
        }
    }
    sort(vec_a_sum.begin(), vec_a_sum.end());
    for (int idx = 0; idx < m; ++idx)
	{
        int i_sum = 0;
        for (int jdx = idx; jdx < m; ++jdx)
		{
            i_sum += i_b[jdx];
            vec_b_sum.push_back(i_sum);
        }
    }
}

void BinarySearch(long long ll_subtotal_b)
{
    long long ll_left = 0;
    long long ll_right = vec_a_sum.size()-1;
    long long ll_left_overlap = -1;
    long long ll_right_overlap = -1;
    while (ll_left <= ll_right)
	{
        long long center = (ll_left + ll_right) / 2;
        if (vec_a_sum[center] + ll_subtotal_b >= T)
		{
            if (vec_a_sum[center] + ll_subtotal_b == T)
                ll_right_overlap=center;
            ll_right = center - 1;
        }
        else if (vec_a_sum[center] + ll_subtotal_b<T)
            ll_left = center + 1;
    }
    ll_left = 0;
   	ll_right = vec_a_sum.size() - 1;
    while (ll_left<=ll_right)
	{
        long long center = (ll_left + ll_right) / 2;
        if (vec_a_sum[center] + ll_subtotal_b > T)
            ll_right=center-1;
        else if (vec_a_sum[center] + ll_subtotal_b<=T)
		{
            if (vec_a_sum[center] + ll_subtotal_b==T)
                ll_left_overlap=center;
            ll_left = center + 1;
        }
    }
    if (ll_left_overlap != -1 && ll_right_overlap != -1)
        ll_cnt += (ll_left_overlap - ll_right_overlap + 1);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> T;
	cin >> n;
    for (int idx = 0; idx < n; ++idx)
        cin >> i_a[idx];
	cin >> m;
    for (int idx = 0; idx < m; ++idx)
		cin >> i_b[idx];
	find_sum();
    for (int idx = 0; idx < vec_b_sum.size(); idx++)
        BinarySearch(vec_b_sum[idx]);
    cout << ll_cnt;
    return 0;
}
