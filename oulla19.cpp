#include<iostream>
using namespace std;

int x[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cnt = 0;

int r(int y) {
    if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) return 1;
    return 0;
}

void ji(int y, int m, int d) {
    int w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    if (w == 6) cnt++;
    return ;
}

int main() {
    for (int y = 1901; y <= 2000; y++) {
        int flag = 1;
        int dup = 0;
        for (int m = 1; m < 13; m++) {
            flag = flag && r(y);
            if (flag && m == 2) dup = 29;
            else dup = x[m];
            if (m == 1 || m == 2) {
                m += 12;
                y--;
            }
            for (int d = 1; d <= dup; d++) {
                ji(y, m, d);
            }
        } 
    }
    cout << cnt << endl;
}
