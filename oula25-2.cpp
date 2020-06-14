#include <iostream>
#define max_n 1000
using namespace std;

int fib[3][max_n + 5] = {
    {0},
    {1, 0},
    {1, 0}
};
int ans = 0;

void init() {
    int  n = 3;
    while (ans < 999) {
        for (int i = 0; i <= ans; i++) {
            fib[n % 3][i] = fib[(n - 1) % 3][i] + fib[(n - 2) % 3][i];
        }
        for (int j = 0; j <= ans; j++) {
            if (fib[n % 3][j] < 10) continue;
            fib[n % 3][j + 1] += (fib[n % 3][j] / 10);
            fib[n % 3][j] %= 10;
            ans += (j == ans);
        }
        n++;
    }
    cout << n - 1 << endl;
}


int main() {
    init();
    return 0;
}
