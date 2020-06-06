#include<iostream>
#define max_n 350
using namespace std;

int ans[max_n + 5] = {1, 0};

int main() {
    int p = 1;
    for (int i = 0; i < 100; i++) {
        for (int j = 1; j <= ans[0]; j++) ans[j] *= 1024;
        for (int k = 1; k <= ans[0]; k++) {
            if (ans[k] < 10) continue;
            ans[k + 1] += ans[k] / 10;
            a[k] %= 10;
            a[0] += (ans[0] == k);
        }
    }
    for (int i = 1; i <= ans[0]; i++) {
        sum += ans[i];
    }
    cout << sum << endl;
    return 0;
}
