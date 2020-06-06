#include<iostream>
using namespace std;

int dir[2][2] = {
    1, 0,
    0, 1
};
int cnt = 0;

void in(int x, int y) {
    if (x > 20 || y > 20) return ;
    if (x == 20 && y == 20) {
        cnt++;
        return ;
    }
    for (int i = 0; i < 2; i++) {
        in(x + dir[i][0], y + dir[i][1]);
    }
}

int main() {
    in(0, 0);
    cout << cnt << endl;
    return 0;
}
