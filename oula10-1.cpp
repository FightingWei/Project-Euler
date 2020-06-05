#include <iostream>
#define max_n 2000000
using namespace std;

int prime[max_n + 5] = {0, 1, 0};
long long ans = 0;

void init() {
    for (int i = 1; i <= max_n; i++) {
        if (!prime[i]) {
            ans += i;
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n)  break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    cout << ans << endl;
}

int main() {
    init();
    return 0;
}