#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<int> V(10000);
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> V[i];
	}
	int y_fee = 0;
	int m_fee = 0;
	for (int i = 0; i < N; ++i) 
	{
		y_fee += ((V[i] / 30) * 10) + 10;
		m_fee += ((V[i] / 60) * 15) + 15;
	}
	if (y_fee < m_fee)
	{
		cout << "Y " << y_fee << '\n';
	}
	else if (y_fee > m_fee)
	{
		cout << "M " << m_fee << '\n';
	}
	else
	{
		cout << "Y " << "M " << m_fee << '\n';
	}
}
