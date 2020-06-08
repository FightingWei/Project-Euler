#include <iostream>
#define max_n 100000
using namespace std;

int a[max_n + 5] = {1, 1, 0};

void init() {
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= a[0]; j++) a[j] *= i;
        for (int k = 1; k <= a[0]; k++) {
            if (a[k] < 10) continue;
            a[k + 1] += (a[k] / 10);
            a[k] %= 10;
            a[0] += (k == a[0]);
        }
    }
    for (int i = a[0]; i > 0; i--) {
        sum += a[i];
    }
    cout << sum << endl;
}


int main() {
    init();
    return 0;
}
