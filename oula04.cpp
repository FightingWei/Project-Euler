#include <iostream>
#define max_n 1000
using namespace std;

int is_val(int x, int base) {
    int tmp = x;
    int a = 0;
    while (tmp) {
        a *= base;
        a += tmp % base;
        tmp /= base;
    }
    return a == x;
}

void init() {
    int ans = 0;
    for (int i = 100; i < max_n; i++) {
        for (int j = i; j < max_n; j++) {
            int s = i * j;
            if (is_val(s, 10) && s > ans) ans = s;
        }
    }
    cout << ans << endl;
    return ;
}

int main() {
    init();
    return 0;
}