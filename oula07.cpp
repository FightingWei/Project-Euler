#include <stdio.h>
#define max_n 10001

void is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int cut = 0, i = 2;
    for (; cut < max_n; i++) {
        if (is_prime(i)) cut++;
    }
    printf("%d\n", i - 1);
    return 0;
}
