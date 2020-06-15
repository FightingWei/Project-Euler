#include <iostream>
#include <algorithm>
#define max_n 2000000
using namespace std;

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};
int sum = 40;

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) is_prime[++is_prime[0]] = i;
        for (int j = 1; j <= is_prime[0]; j++) {
            if (i * is_prime[j] > max_n) break; 
            prime[i * is_prime[j]] = 1;
            if (i % is_prime[j] == 0) break;
        }
    }
    return ;
}

int is_val(int a, int b) {
    int cnt = 0;
    for (int i = 0; ; i++) {
        int s = i * i + a * i + b;
        if (s < 0 || s > max_n) break;
        if (prime[s]) {
            if (sum > cnt) return 0;
            sum = cnt;
            return 1;
        }
        cnt++;
    }
    if (sum > cnt) return 0;
    sum = cnt;
    return 1;
}

int main() {
    init();
    int ans = 1;
    for (int i = 1; i <= is_prime[0]; i++) {
        int b = is_prime[i];
        if (b > 1000) break;
        for (int a = (-1) * b; a <= 1000; a += 2) {
            is_val(a, b) && ans = a * b;
        }
    }
    cout << sum << endl;
    cout << ans << endl;
    return 0;
}
