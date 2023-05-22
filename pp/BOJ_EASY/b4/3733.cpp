/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3733.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 08:54:26 by junto             #+#    #+#             */
/*   Updated: 2022/07/09 08:54:51 by junto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;
typedef long long ll;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;
	while (cin >> x >> y)
	{
		++x;
		cout << y / x << '\n';
	}
}
