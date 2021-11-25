/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1074.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juji <juji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:49:18 by juji              #+#    #+#             */
/*   Updated: 2021/11/25 11:01:46 by juji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

int recur(int n, int r, int c)
{
	int bound;

	if (n == 0)
		return 0;
	bound = 1 << (n - 1); 
	if (r < bound && c < bound)
		return recur(n - 1, r, c); // 1 0 1
	else if (r < bound && c >= bound)
		return bound * bound + recur(n - 1, r, c - bound);
	else if (r >= bound && c < bound)
		return 2 * bound * bound + recur(n - 1, r - bound, c);
	else
		return 3 * bound * bound + recur(n - 1, r - bound, c - bound);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	int r, c;

	// 2 0 1
	cin >> N >> r >> c;
	cout << recur(N, r, c);
}
