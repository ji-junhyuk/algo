#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> vec_primes;
vector<bool> b_check;

int i_sum, i_left, i_right;
int i_result;
int main(void)
{
	cin >> N; 
    b_check.resize(N + 1, 0);
    for (int idx = 2; idx * idx <= N; idx++)
    {
		if (!b_check[idx])
			for (int j = idx * idx; j <= N; j += idx)
				b_check[j] = true;
    }
    for (int idx = 2; idx <= N; idx++)
        if (!b_check[idx]) 
			vec_primes.push_back(idx);
	int i_vec_max_size = vec_primes.size();
    while (i_left <= i_right)
	{
        if (i_sum >= N)
		{
        	if (i_sum == N) 
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
