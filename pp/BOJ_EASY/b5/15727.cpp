/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15727.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junji <junji@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 09:28:05 by junji             #+#    #+#             */
/*   Updated: 2022/05/26 09:28:08 by junji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;
typedef long long ll;

ll L;
ll ans;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L;
	while (1)
	{
		if (L >= 5)
			L -= 5;
		else if (L >= 4)
			L -= 4;
		else if (L >= 3)
			L -= 3;
		else if (L >= 2)
			L -= 2;
		else if (L >= 1)
			L -= 1;
		ans += 1;
		if (!L)
			break ;
	}
	cout << ans;
}
