/*************************************************************************
	> File Name: oula02.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 May 2020 07:36:17 PM CST
 ************************************************************************/

#include<iostream>
#define max_n 4000000
using namespace std;

int fib[3] = {0, 1, 1};

int main() {
    int sum = 0;
    int n = 3;
    while (fib[(n - 2) % 2] + fib[(n - 1) % 3] < max_n) {
        fib[n % 3] = fib[(n - 1) % 3] + fib[(n - 2) % 3];
        if (!(fib[n % 3] & 1)) sum += fib[n % 3];
        n++;
    }
    cout << sum << endl;
    return 0;
}
