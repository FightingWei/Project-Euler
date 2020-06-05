#include <iostream>
#define max_n 2000000
using namespace std;

typedef long long ll;

int prime[max_n + 5] = {0, 1, 0};
int f[max_n + 5] = {0};
int cnt[max_n] = {0};


void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[i * prime[j]] = cnt[i] + 1;
            } else {
                f[prime[j] * i] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = 1;
            }
        }
    }
}

int main() {
    init();
    int fac = 0, n = 0;
    while (fac <= 500) {
        n++;
        if (n & 1) {
            fac = f[n] * f[(n + 1) >> 1];
        } else {
            fac = f[n >> 1] * f[(n + 1)];
        }
    }
    cout << (n * (n + 1) >> 1) << endl;
    return 0;
}
