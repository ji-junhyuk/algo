#include <iostream>
#include <string>
#define MAX 9
using namespace std;
int i_sudoku[MAX][MAX];

int remain_zero(int *p_row, int *p_col)
{
	*p_row = -1;
	while (++(*p_row) < 9)
	{
		*p_col = -1;
		while (++(*p_col) < 9)
		{
			if (i_sudoku[*p_row][*p_col] == 0)
				return (1);
		}
	}
	return (0);
}

int check_col(int i_col, int i_num)
{
	for (int idx = 0; idx < 9; ++idx)
	{
		if (i_sudoku[idx][i_col] == i_num)
			return 0;
	}
	return 1;
}

int check_row(int i_row, int i_num)
{
	for (int idx = 0; idx < 9; ++idx)
	{
		if (i_sudoku[i_row][idx] == i_num)
			return 0;
	}
	return 1;
}

int check_possible_line(int i_row, int i_col, int i_num)
{
	if (check_row(i_row, i_num) && check_col(i_col, i_num) && i_sudoku[i_row][i_col] == 0)
		return 1;
	return 0;
}

int check_possible_quad(int i_row, int i_col, int i_num)
{
	for (int idx = i_row / 3 * 3; idx < i_row / 3 * 3 + 3; ++idx)
	{
		for (int jdx = i_col / 3 * 3; jdx < i_col / 3 * 3 + 3; ++jdx)
		{
			if (i_sudoku[idx][jdx] == i_num)
				return 0;
		}
	}
	return 1;
}

int dfs(void)
{
	int i_row;
	int i_col;
	int i_num;
	if (!remain_zero(&i_row, &i_col))
		return (1);
	i_num = 0;
	while (++i_num <= 9)
	{
		if (check_possible_line(i_row, i_col, i_num) && check_possible_quad(i_row, i_col, i_num))
		{
			i_sudoku[i_row][i_col] = i_num;
			if (dfs() == 1)
				return 1;
			i_sudoku[i_row][i_col] = 0;
		}
	}
	return (0);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int idx = 0; idx < 9; ++idx)
	{
		string s_line;
		cin >> s_line;
		for (int jdx = 0; jdx < s_line.length(); jdx++)
			i_sudoku[idx][jdx] = s_line[jdx] - '0';
	}
	dfs();
	for (int idx = 0; idx < 9; ++idx)
	{
		for (int jdx = 0; jdx < 9; ++jdx)
			cout << i_sudoku[idx][jdx];
		cout << '\n';
	}
	//bactracking 문제. dfs
	//- 완료조건
	//	- 1. 0~8행을 체크해서 중복되는 숫자가 있는지 체크
	//	- 2. 0~8열을 체크해서 중복되는 숫자가 있는지 체크
	//	- 3. 0,1,2행-0,1,2열 체크해서 중복되는 숫자가 있는지 체크    - 4. 3,4,5행-3,4,5열 
	//	- 5. 6,7,8행-6,7,8열
//	-> (x / 3) * 3
	//	- 1~5번을 통해 중복되는 숫자가 없고, 0이 없다면 완료.
	//- dfs구현
}
