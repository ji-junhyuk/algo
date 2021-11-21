#include <iostream>
using namespace std;
int map[129][129], b = 0, w = 0;

void solution(int x, int y, int len){
    int tmp = 0;
    for(int i = x; i < x + len; i++){
        for(int j = y; j < y + len; j++){
            if(map[i][j]) tmp++;
        }
    }

    if(!tmp) w++;
    else if(tmp == len * len) b++;
    else{
        solution(x, y, len / 2);
        solution(x + len / 2, y, len / 2);
        solution(x, y + len / 2, len / 2);
        solution(x + len / 2, y + len / 2, len / 2);
    }
    return;
}

int main(void){
    cin.tie(0); cin.sync_with_stdio(0);
    int num; cin >> num;

    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= num; j++)
            cin >> map[i][j];
    }

    solution(1, 1, num);
    cout << w << "\n"; cout << b << "\n";
    return 0;
}
