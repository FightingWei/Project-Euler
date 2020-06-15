#include <stdio.h>

int main() {
    int sum = 1;
    for (int l = 3; l <= 1001; l += 2) {
        sum += 4 * l * l - 6 * l + 6;
    }
    printf("%d\n", sum);
    return 0;
}