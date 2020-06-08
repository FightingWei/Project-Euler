#include <iostream>
#define max_n 28123
using namespace std;

int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0, 1, 0};
int prime[max_n + 5] = {0};
//int keep[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = i + 1;
            cnt[i] = i * i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                cnt[prime[j] * i] = cnt[i] * prime[j];
                f[prime[j] * i] = f[i] * (cnt[i] * prime[j] - 1) / (cnt[i] - 1);
                break;
            } else {
                cnt[prime[j] * i] = prime[j] * prime[j];
                f[prime[j] * i] = f[prime[j]] * f[i];
            }
        }
    }
}

int main() {
    init();
    for (int i = 1; i <= max_n; i++) {
        if (f[i] - i <= i) continue; 
        for (int j = 1; j <= max_n; j++) {
            if (f[j] - j <= j || i + j > max_n) continue;
            cnt[i + j] = 0;
        }
    }
    int sum = 0;
    for (int i = 1; i <= max_n; i++) {
        if (cnt[i]) sum += i;
    }
    cout << sum << endl;
    return 0;
}