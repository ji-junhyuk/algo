/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2448.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junji <junji@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:37:24 by junji             #+#    #+#             */
/*   Updated: 2022/05/24 14:52:43 by junji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;
#define ll long long
#define MAX_LEN 3072

char board[MAX_LEN][MAX_LEN * 2 + 1];
int N;

void	print_star(int row, int col)
{
	board[row][col] = '*';
	board[row + 1][col - 1] = '*';
	board[row + 1][col + 1] = '*';
	for (int idx = 0; idx < 5; ++idx)
		board[row + 2][col - 2 + idx] = '*';
}

void	recur(int row, int col, int high)
{
	if (high == 3)
	{
		print_star(row, col);
		return ;
	}
	high = (high >> 1);
	recur(row, col, high);
	recur(row + high, col - high, high);
	recur(row + high, col + high, high);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 0; idx < N; ++idx)
		for (int jdx = 0; jdx < 2 * N - 1; ++jdx)
			board[idx][jdx] = ' ';
	recur(0, N - 1, N);
	for (int idx = 0; idx < N; ++idx)
	{
		for (int jdx = 0; jdx < 2 * N - 1; ++jdx)
			cout << board[idx][jdx];
		cout << '\n';
	}
	return (0);
}
