#include <iostream>
#define max_n 1000
using namespace std;

int dir[4][2] = {
    1, 0,
    0, 1,
    1, 1,
    -1, 1
};
int ans = 0;
int num[25][25] = {0};

void cat(int i, int j, int k) {
    int temp = 1;
    for (int s = 0; s < 4; s++) {
        int x = i + s * dir[k][0];
        int y = j + s * dir[k][1];
        temp *= num[x][y];
        if (x > 20 || x < 1 || y > 20 || y < 1) return ;
    }
    if (temp > ans) ans = temp;
    return ;
}

void init() {
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            for (int k = 0; k < 4; k++) {
                cat(i, j, k);
            }
        }
    }
}

int main() {
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            cin >> num[i][j];
        }
    }
    init();
    cout << ans << endl;
    return 0;
}
