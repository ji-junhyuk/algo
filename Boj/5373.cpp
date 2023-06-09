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

int N;
char color[] = {'w', 'y', 'r', 'o', 'g', 'b'};
char cube[6][3][3];				
const int UP = 0;
const int DOWN = 1;
const int FRONT = 2;
const int BACK = 3;
const int LEFT = 4;
const int RIGHT = 5;
	
void rotate_cube_side(int side, char rotate){
	int ro = 1;
	if (rotate == '-')
		ro = 3;
	while (--ro >= 0)
	{
		char tmp[3][3];
		for (int i = 0; i < 3; ++i) 
		{
			for (int j = 0; j < 3; ++j) 
			{ 
				tmp[j][3 - 1 - i] = cube[side][i][j];
			}
		}
		swap(cube[side], tmp);
	}
}

void rotate_cube(int side, char rotate)
{
	int ro = 1;
	int tmp;
	if (rotate == '-')
		ro = 3;
	rotate_cube_side(side, rotate);
	while (--ro >= 0)
	{
		if (side == FRONT)
		{
			for (int i = 0; i < 3; ++i) 
			{
				tmp = cube[UP][2][i];
        		cube[UP][2][i] = cube[LEFT][2 - i][2];
				cube[LEFT][2 - i][2] = cube[DOWN][0][2 - i];
				cube[DOWN][0][2 - i] = cube[RIGHT][i][0];
				cube[RIGHT][i][0] = tmp;
			}
		}
		else if (side == BACK)
		{
			for (int i = 0; i < 3; ++i) 
			{
				// UP -< RIGHT <-DOWN -< LEFT
				tmp = cube[UP][0][i];
				cube[UP][0][i] = cube[RIGHT][i][2];
				cube[RIGHT][i][2] = cube[DOWN][2][2 - i];
				cube[DOWN][2][2 - i] = cube[LEFT][2 - i][0];
				cube[LEFT][2 - i][0] = tmp;
			}
		}
		else if (side == LEFT)
		{
			for (int i = 0; i < 3; ++i) 
			{
				// UP -< B -< DOWN -< FRONT
				tmp = cube[UP][i][0];
				cube[UP][i][0] = cube[BACK][i][0];
				cube[BACK][i][0] = cube[DOWN][i][0];
				cube[DOWN][i][0] = cube[FRONT][i][0];
				cube[FRONT][i][0] = tmp;
			}
		}
		else if (side == RIGHT)
		{
			for (int i = 0; i < 3; ++i) 
			{
				// UP <= FRONT <= DOWN <= BACK
				tmp = cube[UP][i][2];
				cube[UP][i][2] = cube[FRONT][i][2];
				cube[FRONT][i][2] = cube[DOWN][i][2];
				cube[DOWN][i][2] = cube[BACK][i][2];
				cube[BACK][i][2] = tmp;
			}
		}
		else if (side == UP)
		{
			for (int i = 0; i < 3; ++i) 
			{
				// FRONT <- RIGHT <- BACK -< LEFT
				tmp = cube[FRONT][0][i];
				cube[FRONT][0][i] = cube[RIGHT][0][i];
				cube[RIGHT][0][i] = cube[BACK][2][2 - i];
				cube[BACK][2][2 - i] = cube[LEFT][0][i];
				cube[LEFT][0][i] = tmp;
			}
		}
		else if (side == DOWN)
		{
			// FRONT -< LEFT -< BACK -< RIGHT
			for (int i = 0; i < 3; ++i) 
			{
				tmp = cube[FRONT][2][i];
				cube[FRONT][2][i] = cube[LEFT][2][i];
				cube[LEFT][2][i] = cube[BACK][0][2 - i];
				cube[BACK][0][2 - i] = cube[RIGHT][2][i];
				cube[RIGHT][2][i] = tmp;
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int idx = 0; idx < 6; ++idx) 
		{
			for (int jdx = 0; jdx < 3; ++jdx) 
			{
				for (int kdx = 0; kdx < 3; ++kdx) 
				{
					cube[idx][jdx][kdx] = color[idx];
				}
			}
		}
		int num;
		cin >> num;
		string s;
		while (num--)
		{
			cin >> s;
			if(s[0] == 'F') rotate_cube(FRONT, s[1]);
			else if(s[0] == 'B') rotate_cube(BACK, s[1]);
			else if(s[0] == 'U') rotate_cube(UP, s[1]);
			else if(s[0] == 'D') rotate_cube(DOWN, s[1]);
			else if(s[0] == 'L') rotate_cube(LEFT, s[1]);
			else rotate_cube(RIGHT, s[1]);
		}
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
				cout << cube[UP][i][j];
			cout << '\n';
		}
	}
}

