#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
 
// q[rotate][m][x, y]
// d[rotate][m][x, y]

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
 
int q[4][4][2] = {  {{-1,-1},{-1,1},{1,1},{1,-1}},
                    {{1,1},{-1,1},{-1,-1},{1,-1}},
                    {{1,1},{1,-1},{-1,-1},{-1,1}},
                    {{-1,-1},{1,-1},{1,1},{-1,1}}};
 
int d[4][4][2] = {  {{0,0},{0,1},{1,1},{1,0}},
                    {{1,1},{0,1},{0,0},{1,0}},
                    {{1,1},{1,0},{0,0},{0,1}},
                    {{0,0},{1,0},{1,1},{0,1}}}; 
 
int r[4][2] = {{3,1},{2,0},{1,3},{0,2}};
 
 

void recur(int n, int m, int rotate, int x, int y)
{
 
    if(n==2)
		printf("%d %d\n",x+d[rotate][m][0],y+d[rotate][m][1]);
    else 
	{
		printf("\nx + d[rotate][m][0], y + d[rotate][m][1]\n\n");
		printf("%d %d %d %d %d\n", n, m, rotate, x, y);
        int new_n = n/2;
		printf("new_n: %d -> n / 2\n", new_n);
        int quadrant = m / (new_n * new_n);
		printf("quadrant: %d -> m / (new_n * new_n) -> m :%d \n", quadrant, m);
        int new_m = m - quadrant * (new_n*new_n);
		printf("new_m: %d -> m - q * (new_n * new_n)\n", new_m);
 
        int new_rotate;
 
		printf("rotate: %d\n", rotate);
        if(quadrant==0||quadrant==3){
		   	new_rotate = r[rotate][quadrant==0?0:1];
		printf("new_rotate: %d -> q == 0 || q == 3 r[rotate][quadrant==0?0:1]\n", r[rotate][quadrant==0?0:1]);
		}
        else new_rotate = rotate;
 
		printf("x += q[rotate][quadrant][0] * new_n / 2 q[%d][%d] * %d , y += q[rotate][quadrant][1]\n", rotate, quadrant, new_n/2);
        x += q[rotate][quadrant][0]*(new_n/2);
        y += q[rotate][quadrant][1]*(new_n/2);
 
		printf("%d %d %d %d %d\n", new_n, new_m, new_rotate, x, y);
        recur(new_n,new_m,new_rotate, x, y);
    }
}

int main()
{
	int n;
	int m;

	scanf("%d %d",&n,&m);
	recur(n, m - 1, 0, n / 2, n / 2);
}
