#include <iostream>
#include <algorithm>
#define max_n 15
using namespace std;

int a[max_n + 5][max_n + 5];
int keep[max_n + 5][max_n + 5] = {0};

void dfs(int i, int j, int n) {
    if (i + 1 == n) return arr[i][j];
    if(keep[i][j]) return keep[i][j];
    int val1 = dfs(i + 1, j, n); 
    int val2 = dfs(i + 1, j + 1, n);
    return keep[i][j] = max(val1, val2) + a[i][j];
}

int main() {
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    cout << dfs(0, 0, max_n)
    return 0;
}
