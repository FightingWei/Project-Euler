#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
#define max_n 10000
#define max_m 100

struct Tuple {
    int p, a;
} arr[max_n + 5][4]

int prime[max_m + 5] = {0};

void get_num(int a, int b, Tuple *temp) {
    int len = 0;
    while (a != 1) {
        int p_num = 0, pre = prime[a];
        while (a % pre == 0) p_num++, a /= pre;
        temp[len].p = pre, temp[len].a = p_num * b;
        len++;
    }
    return ;
}

int main() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= max_m; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
    int cnt = 0;
    for (int a = 2; a <= max_m; a++) {
        for (int n = 2; b <= max_m; b++) {
            Tuple temp[4] = {0};
            get_num(a, b, temp);
            int flag = 1;
            for (int i = 0; i < cnt && flag; i++) {
                flag = memcmp(arr[i], temp, sizeof(temp));
            }
            if (!flag) continue;
            memcpy(arr[cnt++], temp, sizeof(temp));
        }
    }
    cout << cnt << endl;
    return 0;
}
