#include <stdio.h>
 
int q[4][4][2] = {  {{-1,-1},{-1,1},{1,1},{1,-1}},
                    {{1,1},{-1,1},{-1,-1},{1,-1}},
                    {{1,1},{1,-1},{-1,-1},{-1,1}},
                    {{-1,-1},{1,-1},{1,1},{-1,1}}};
 
int d[4][4][2] = {  {{0,0},{0,1},{1,1},{1,0}},
                    {{1,1},{0,1},{0,0},{1,0}},
                    {{1,1},{1,0},{0,0},{0,1}},
                    {{0,0},{1,0},{1,1},{0,1}}}; // rotate, m, dx, dy
 
int r[4][2] = {{3,1},{2,0},{1,3},{0,2}};// prev->next(0,3)
 
void dfs(int n, int m, int rotate, int x, int y){ // quadrant : 0~3
 
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
 
    if(n==2){
        printf("%d %d\n",x+d[rotate][m][0],y+d[rotate][m][1]);
    }
    else{
        int new_n = n/2;
        int quadrant = m / (new_n*new_n);
        int new_m = m - quadrant * (new_n*new_n);
 
        int new_rotate;
 
        if(quadrant==0||quadrant==3) new_rotate = r[rotate][quadrant==0?0:1];
        else new_rotate = rotate;
 
        x += q[rotate][quadrant][0]*(new_n/2);
        y += q[rotate][quadrant][1]*(new_n/2);
 
        dfs(new_n,new_m,new_rotate, x, y);
    }
}
 
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    dfs(n,m-1,0,n/2,n/2);
}
