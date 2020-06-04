#include <iostream>
#define max_n 1000
using namespace std;

char num[max_n + 5];

int main() {
    int len = 0;
    long long ans = 1, p = 0;
    int zero = 0;
    while(~scanf("%c", &num[len])) len++;
    for (int i = 0; num[i]; i++) {
        num[i] -= '0';
        if (num[i]) ans *= num[i];
        else zero++;
        if (i - 13 < 0) continue;
        if (num[i - 13]) ans /= num[i - 13];
        else zero--;
        if (!zero && ans > p) p = ans;
    }
    cout << p << endl;
    return 0;
}
