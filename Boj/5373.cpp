#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;


//   o(3)
// g(4) y(1) b(5) w(0)
//   r(2)
//
// w의 색깔
//
//

int N;
int cube[6][3][3]; // 0번의 색깔만..
	
void rotate_cube(char dir, char rotate)
{
	int ro = 1;
	if (rotate == '-')
	{
		ro = 3;
	}
	while (--ro >= 0)
	{
		rotate_cube_side(dir, rotate);
	}
	if (dir == 0)
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 6; ++i) 
	{
		for (int j = 0; j < 3; ++j) 
		{
			for (int k = 0; k < 3; k++) 
			{
				cube[i][j][k] = i;
			}
		}
	}
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; ++j) 
		{
			char dir, rotate;
			cin >> dir >> rotate;
			rotate_cube(dir, rotate);
		}
	}

}

void rotate_front()


