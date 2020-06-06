#include <iostream>
#define max_n 400
using namespace std;

int a[max_n + 5] = {1, 1, 0};

void init() {
    int len = 100;
    while (len) {
        for (int i = 1; i <= a[0]; i++) a[i] *= 1024;
        for (int j = 1; j <= a[0]; j++) {
            if (a[j] < 10) continue;
            a[j + 1] += (a[j] / 10);
            a[j] %= 10;
            a[0] += (j == a[0]);
        }
        len--;
    }
    int ans = 0;
    for (int i = a[0]; i > 0; i--) {
        ans += a[i];
    }
    cout << ans << endl;
    return ;
}

int main() {
    init();
    return 0;
}
