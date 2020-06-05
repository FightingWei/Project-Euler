#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (primr[j] * i > max_n) break;
            prime[j * i] = 1;
            if (i & prime[j] == 0) break;
        }
        long long sum = 0;
        for (int i = 1; i <= prime[0]; i++) {
            sum += prime[i];
        }
        printf("%lld\n", sum);
    return 0;
}
