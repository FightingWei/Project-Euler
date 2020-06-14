#include <iostream>
#include <maath.h>
#define max_n 1000
using namespace std;

int fib[3][max_n + 5] = {{0, 1}, {1, 1}, {1, 1}};

int main() {
    int n = 2;
    while (floor(log10fib[n % 3]) + 1 < max_n) {
        n++;
        fib[n % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
        a[0] = b[0];
        for (int i = 1; i <= a[0]; i++) {
            if (a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (i == a[0]);
        }
    }
    cout << n << endl;
    return 0;
}
