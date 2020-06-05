#include<iostream>
using namespace std;

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            fi[i] = 2;
            cut[i] = 1; 
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                f[prime[j] * i] = f[i] / (cut[i] + 1) * (cut[i] + 2);
                cut[prime[j] * i] = cut[i] + 1;
                break;
            } else {
                cut[prime[j] * i] = 1;
                f[prime[j * i]] = f[prime[j]] * f[i];
            }
        }
    }
}

int main() {
    init();
    int n = 0, fac = 0;
    while (fac <= 500) {
        n++;
        if (n & 1) {
            fac = f[n] * f[(n + 1) >> 1];      
        } else {
            fac = f[n >> 1] * f[n + 1];
        }
    }
    cout << n * (n + 1) / 2 << endl;
    return 0;
}
