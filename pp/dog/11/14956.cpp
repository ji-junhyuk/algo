#include <bits/stdc++.h>
using namespace std;

// q[rotate][m][x, y]
// d[rotate][m][x, y]
int q[4][4][2] = {  {{-1,-1},{-1,1},{1,1},{1,-1}},
                    {{1,1},{-1,1},{-1,-1},{1,-1}},
                    {{1,1},{1,-1},{-1,-1},{-1,1}},
                    {{-1,-1},{1,-1},{1,1},{-1,1}}};

int d[4][4][2] = {  {{0,0},{0,1},{1,1},{1,0}},
                    {{1,1},{0,1},{0,0},{1,0}},
                    {{1,1},{1,0},{0,0},{0,1}},
                    {{0,0},{1,0},{1,1},{0,1}}};
// rotate 0
//   __
//  |  |

// rotate 1
//   ___
//  |___

// rotate 2
//  |   |
//   ---

// rotate 3
//   __
//   __|


int r[4][2] = {{3,1},{2,0},{1,3},{0,2}};

void recur(int n, int m, int rotate, int x, int y)
{

    if(n==2)
		cout << x + d[rotate][m][0] << ' ' << y + d[rotate][m][1];
    else
        {
        int new_n = n / 2;
        int quadrant = m / (new_n * new_n);
        int new_m = m - quadrant * (new_n * new_n);

        int new_rotate;

        if (quadrant == 0 || quadrant == 3)
			new_rotate = r[rotate][quadrant==0?0:1];
        else 
			new_rotate = rotate;
        x += q[rotate][quadrant][0] * (new_n / 2);
        y += q[rotate][quadrant][1] * (new_n / 2);
        recur(new_n,new_m,new_rotate, x, y);
    }
}

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n;
        int m;

        cin >> n >> m;
        recur(n, m - 1, 0, n / 2, n / 2);
}
