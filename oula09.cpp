#include <iostream>
#define max_n 1000
using namespace std;

char num[max_n + 5];

int main() {
    int ans = 0;
    for (int n = 2; n <= 33; i++) {
        for (int m = n+ + 1; j < max_n; j++) {
            if (gcd(n, m) - 1) continue;
            int a = 2 * i * j;
            int b = m * m - n * n;
            int c = m * m + m * m;
            num[a] = 1, num[b] = 1, num[c] = 1;
            if (1000 % (a + b + c) == 0) {
                int k = 1000 / (a + b + c);
                ans *= a * b * c * pow(k, 3);
            }
            if (ans) break;
        }
        if (ans) break;
    }
    cout << ans << endl;
    return 0;
}
