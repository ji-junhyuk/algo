#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll D, H, W;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> D >> H >> W;
	double diag = sqrt(H * H + W * W);
	double height = H * D / diag;
	double weight = W * D / diag;
	cout << (int)height << ' ' << (int)weight;
	/*
	 * 주어진 대각선을 통해 <비율> 구해준다.
	 * 실제 높이를 구하기 위해 <높이비율 * 비율>을 곱해준다.
	 * 실제 너비를 구하기 위해 <너비비율 * 비율>을 곱해준다.
	 */
}
