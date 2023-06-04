#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

//clockwise




string gear[5];
void rotates(int index, int dir)
{
	char temp[8] = {};
	for (int i = 0; i < 8; ++i) 
	{
		temp[i] = gear[index][i];
	}
	if (dir == 1)
	{
		for (int i = 0; i < 8; ++i) 
		{
			if (i == 7)
			{
				gear[index][0] = temp[i];
				continue ;
			}
			gear[index][i + 1] = temp[i];
		}
	}
	else
	{
		for (int i = 0; i < 8; ++i) 
		{
			if (i == 7)
			{
				gear[index][i] = temp[0];
				continue ;
			}
			gear[index][i] = temp[i + 1];
		}
	}
}
// 1 2 3 4
// 1 -> 2번이랑 2의 6번이랑 비교해서 다르다면
// 2의 2번이랑 3의 6번이랑 비교해서 다르다면
// 3의 2번이랑 4의 6번이랑 비교해서 다르다면 3개가 회전..
int K;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 4; ++i) 
	{
		cin >> gear[i];
	}
	cin >> K;
	for (int i = 0; i < K; ++i) 
	{
		int number, rotate;
		cin >> number >> rotate;
		int rotate_gear[5] = {}; // 회전여부를 담을래
		int rotate_info[5] = {}; // 회전 방향을 담을래
		rotate_gear[number] = 1;
		rotate_info[number] = rotate;
		// number3

		int num = number;
		int ro = rotate;
	//2
		while (--num >= 1)
		{
			char curr_gear = gear[num + 1][6];
			char before_gear = gear[num][2];
//			cout << "curr_gear: " << curr_gear << " before_gear: " << before_gear << '\n';
			if (curr_gear == before_gear)
				break ;
			ro *= -1;
			rotate_gear[num] = 1;
			rotate_info[num] = ro;
		}
		num = number;
		ro = rotate;
		while (++num <= 4)
		{
			char curr_gear = gear[num - 1][2];
			char before_gear = gear[num][6];
//			cout << "curr_gear: " << curr_gear << " before_gear: " << before_gear << '\n';
			if (curr_gear == before_gear)
				break ;
			ro *= -1;
			rotate_gear[num] = 1;
			rotate_info[num] = ro;
		}
		for (int s = 1; s < 5; ++s) 
		{
			if (rotate_gear[s])
			{
				if (rotate_info[s])
				{
					rotates(s, rotate_info[s]);
				}
			}
		}
//		for (int i = 1; i < 5; ++i) 
//		{
//			std::cout << gear[i] << '\n';
//		}
	}
	int score = 0;
	for (int i = 1; i < 5; ++i) 
	{
		if (i == 1 && gear[i][0] == '1')
			score += 1;
		else if (i == 2 && gear[i][0] == '1')
			score += 2;
		else if (i == 3 && gear[i][0] == '1')
			score += 4;
		else if (i == 4 && gear[i][0] == '1')
			score += 8;
	}
	cout << score << '\n';
}
