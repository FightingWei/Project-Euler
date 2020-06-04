#include<iostream>
using namespace std;

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

void init() {
    int ans = 1;
    for (int i = 1; i <= 20; i++) {
        ans = ans * (i / gcd(ans, i));
    }  
    cout << ans << endl;
}

int main() {
    init();
    return 0;
}