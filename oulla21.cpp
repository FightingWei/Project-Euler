#include <iostream>
#define max_n 10000
using namespace std;

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};

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
    return ;
}

int main() {
    init();
    for (int i = 2; i < max_n; i++) {
        f[i] -= i;
    }
    long long sum = 0;
    for (int i = 2; i < max_n; i++) {
        if (i == f[f[i]] && f[i] < max_n && i != f[i]) sum += i;
    }
    cout << sum << endl;
    return 0;
}
