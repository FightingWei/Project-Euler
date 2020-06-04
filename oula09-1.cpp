#include <iostream>
#define max_n 1000
#include <math.h>
using namespace std;

int gcd(int n1, int n2) {
    return (n2 ? gcd(n2, n1 % n2) : n1);
}

int main() {
    for (int n = 1; n <= 33; n++) {
        int flag = 0;
        for (int m = n + 1; m <= 33; m++) {
            if (gcd(n, m) - 1) continue;
            int a = 2 * n * m;
            int b = m * m - n * n;
            int c = m * m + n * n;
            int s = a + b + c;
            int k = 1;
            for (int i = s; i <= max_n; i += s) {
                if (i == 1000) {
                    flag = 1;
                    cout << a * b * c * (int)pow(k, 3)<< endl;
                }
                k++;
            }
            if (flag) break;
        }
        if (flag) break;
    }
    return 0;
}
