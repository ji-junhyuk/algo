#include <iostream>
#include <algorithm>
# define MAX 1000
using namespace std;

int i_lcs_length[MAX + 1][MAX + 1];
string result;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s_s1, s_s2;
	cin >> s_s1 >> s_s2;
	int i_s1_size = s_s1.length();
	int i_s2_size = s_s2.length();
	for (int idx = 1; idx <= i_s1_size; ++idx)
	{
		for (int jdx = 1; jdx <= i_s2_size; ++jdx)
		{
			if (s_s1[idx - 1] == s_s2[jdx - 1])
				i_lcs_length[idx][jdx] = i_lcs_length[idx - 1][jdx - 1] + 1;
			else
				i_lcs_length[idx][jdx] = max(i_lcs_length[idx - 1][jdx], i_lcs_length[idx][jdx - 1]);
		}
	}
	cout << i_lcs_length[i_s1_size][i_s2_size] <<'\n';
	while (i_s1_size != 0 && i_s2_size != 0)
	{
		if (i_lcs_length[i_s1_size][i_s2_size] == i_lcs_length[i_s1_size - 1][i_s2_size])
			i_s1_size--;
		else if (i_lcs_length[i_s1_size][i_s2_size] == i_lcs_length[i_s1_size][i_s2_size - 1])
			i_s2_size--;
		else
		{
			result += s_s1[i_s1_size - 1];
			i_s1_size--;
			i_s2_size--;
		}
	}
	reverse(result.begin(), result.end());
	cout << result;
}
