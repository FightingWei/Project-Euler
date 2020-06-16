#include <iostream>
#include <math.h>
#define max_n 354294
using namespace std;

int sum = 0;
int k[10] = {0};

void init() {
    for (int i = 1; i < 10; i++) {
        k[i] = pow(i, 5);
    }
    return ;
}

int get_num (int a) {
    int ans = 0;
    int temp = a;
    while (temp) {
        ans += k[temp % 10];
        temp /= 10;
    }
    return (ans == a);
}

int main() {
    init();
    for (int i = 1; i <= max_n; i++) {
        if (get_num(i)) sum += i;
    }    
    cout << sum << endl;
    return 0;
}
