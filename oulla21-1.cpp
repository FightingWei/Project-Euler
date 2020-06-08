#include<iostream>
#define max_n 10000
using namespace std;

int prime[max_n + 5] = {0};
int cnt[max_n + 5] = {0};
int f[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            f[i] = i + 1;
            cnt[i] = i * i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                f[i * prime[j]] = f[i] * (cnt[i] * prime[j] - 1) / (cnt[i] - 1);
                cnt[i * prime[j]] = cnt[i] * prime[j];
                break;
            } else {
                f[i * prime[j]] = f[i] * f[prime[j]];
                cnt[i * prime[j]] = prime[j] * prime[j];
            }
        }
    }
    return ;
}

int main() {
    init();
    long long ans = 0;
    for (int i = 2; i < max_n; i++) {
        f[i] -= i;
    }
    for (int i = 2; i <= max_n; i++) {
        if (f[i] < max_n && f[f[i]] == i && i != f[i]) ans += i;
    }
    cout << ans << endl;
    return 0;
}
