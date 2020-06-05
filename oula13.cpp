#include <iostream>
#include <string.h>
#define max_n 53
using namespace std;

char str[amx_n + 5];
int ans[max_n + 5] = {0};

int main() {
    for (int i = 0; i < 100; i++) {
        cin >> str;
        int len = strlen(str);
        if (ans[0] < len) ans[0] = len;
        for (int i = 1; i < len; i++) {
            ans[len - i] += str[i] - '0';
        }
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
