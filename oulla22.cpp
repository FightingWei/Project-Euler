#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "nams.txt"
using namespace std;

bool cmp(string a, string b) {
    return a < b;
}

int add_to_num(string str, int n) {
    for (int i = 0; str[i]; i++) {
        ret += str[i] - 'A' + 1;
    }
    return ret * n;
}

int main() {
    int n = 0;
    for (int i = 0; names[i] != "\0"; i++) n++;
    sort(numes, names + n, cmp);
    for (int i = 0; i < n; i++) {
        sum += add_to_num(names[i], i + 1);
    } 
    cout << sum << endl;
    return 0;
}
