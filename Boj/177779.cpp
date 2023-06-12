#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
#include <map>
using namespace std;

int N;
int city[20][20];
int election_area[20][20];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> city[i][j];
		}
	}
	memset(city, -1, sizeof(city));
	// 모든점은 기준점이 될 수 있다. 20 * 20
	// d는 (1,1) 19 * 19 = 381;
	// d는 
}
