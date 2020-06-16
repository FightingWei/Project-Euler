#include <iostream>
#include <algorithm>
#include <string.h>
#define max_n 10000
using namespace std;

int num[10] = {0};
int sum = 0;
int cnt = 0;
int keep[max_n + 5] = {0};

int is_num(int k) {
    int temp = k;
    while (temp) {
        if (!(temp % 10))  return 0;
        if (num[temp % 10]) return 0;
        num[temp % 10] = 1;
        temp /= 10;
        cnt++;
    }
    return 1;
}

int is_val(int x, int y, int z) {
    cnt = 0;
    memset(num, 0, sizeof(num));
    int flag = 1;
    flag = flag && is_num(x);
    flag = flag && is_num(y);
    flag = flag && is_num(z);
    flag = flag && (cnt == 9);
    return (flag == 1);
}

int main() {
    int k;
    for (int i = 100; i < max_n; i++) {
        for (int j = 1; j < 100; j++) {
            int s = i * j;
            if (is_val(i, j, s) && !keep[s]) {
                sum += s;
                keep[s] = 1;
            }
        }
    }
    /*for (int i = 1000; i < 10000; i++) {
        if (!is_val(i))  c
        for (int j = 1; j < 10; j++) {
            if (is_va*/
    cout << sum << endl;
    return 0;
}
