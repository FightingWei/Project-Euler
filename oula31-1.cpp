#include <iostream>
#define max_n 8
#define max_m 200
using namespace std;

int f[max_n + 5][max_m + 5];
int w[max_n + 5] = {1, 2, 5, 10, 20, 50, 100, 200};

int main() {
    for (int i = 0; i < max_n; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= max_m; j++) {
            f[i][j] = 0;
            if (i >= 1) f[i][j] += f[i - 1][j];
            if (j >= w[i]) f[i][j] += f[i][j - w[i]];
        }
    }
    cout << f[max_n - 1][max_m] << endl;
    return 0;
}
