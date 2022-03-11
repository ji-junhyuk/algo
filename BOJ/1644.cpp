#include <iostream>
#include <vector>
# define MAX 4000000
using namespace std;

int n;
vector<int> vec_primes;
bool b_check[MAX]; // is prime 0

int i_sum, i_left, i_right;
int i_result;
int main(void)
{
	cin >> n;
    for (int idx = 2; idx * idx <= n; idx++)
    {
		if (!b_check[idx])
			for (int j = idx * idx; j <= n; j += idx)
				b_check[j] = true;
    }
    for (int idx = 2; idx <= n; idx++)
        if (!b_check[idx]) 
			vec_primes.push_back(idx);
	int i_vec_max_size = vec_primes.size();
    while (i_left <= i_right)
	{
        if (i_sum >= n)
		{
        	if (i_sum == n) 
				i_result++;
            i_sum -= vec_primes[i_left];
			i_left++;
		}
		else if (i_right == vec_primes.size())
			break;
        else
		{
            i_sum += vec_primes[i_right];
			i_right++;
		}
    }
    cout << i_result;
    return 0;	
}
