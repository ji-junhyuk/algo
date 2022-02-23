/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11053.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juji <juji@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:12:51 by juji              #+#    #+#             */
/*   Updated: 2022/02/23 17:28:52 by juji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# define MAX 1001
using namespace std;

int N, length;
int arr[MAX];
int dp[MAX];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 1; idx <= N; idx++)
		cin >> arr[idx];	
	for (int idx = 1; idx <= N; idx++)
	{
		dp[idx] = 1;
		for (int jdx = idx - 1; jdx >= 1; jdx--)
		{
			if (arr[idx] > arr[jdx])
				dp[idx] = max(dp[idx], dp[jdx] + 1);
		}	
		length = max(dp[idx], length);
	}
	cout << length;
}
