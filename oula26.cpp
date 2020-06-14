#include <iostream>
#include <string.h>
#define max_n 1000
using namespace std;

int cnt = 0;
int ans = 0;
int keep[max_n + 5] = {0};


int get_len(int x) {
    memset(keep, 0, sizeof(keep));
    int t = 1, r = 1;
    while (r) {
        keep[r] = t;
        r *= 10;
        r %= x;
        t++;
        if (keep[r]) return t - keep[r];
    }
    return 0;
}
    

int main() {
    for (int i = 2; i <= 1000; i++) {
        int s = get_len(i);
        if (s > ans) {
            ans = s;
            cnt = i;
        }
    }
    cout << cnt << endl;
    return 0;
}
