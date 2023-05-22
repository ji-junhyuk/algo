#include <bits/stdc++.h>
using namespace std;

int arr[3];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	int right_triangle;
	while (1)
	{
		cin >> arr[0] >> arr[1] >> arr[2];
		if (!arr[0] && !arr[1] && !arr[2])
			break;
		for (int idx = 0; idx < 2; idx++)
		{
			for (int jdx = 0; jdx < 2; jdx++)
			{
				if (arr[jdx] > arr[jdx + 1])
				{
					int temp;
					temp = arr[jdx];
					arr[jdx] = arr[jdx + 1];
					arr[jdx + 1] = temp;
				}
			}
		}
		right_triangle = arr[0] * arr[0];
		right_triangle += arr[1] * arr[1];
		if (right_triangle == arr[2] * arr[2])
			cout << "right\n";
		else
			cout << "wrong\n";
	}
}
