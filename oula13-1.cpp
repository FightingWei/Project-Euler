#include <iostream>
using namespace std;

int arr[105] = {0};
int ans = 49;
char num[100][50] = {0};

void init() {
    for (int i = 0; i < 100; i++) {
        for (int j = 49; j >= 0; j--) arr[49 - j] += (num[i][j] - '0');
        for (int k = 0; k <= ans; k++) {
            if (arr[k] < 10) continue;
            arr[k + 1] += (arr[k] / 10);
            arr[k] %= 10;
            ans += (k == ans);
        }
    }
    for (int i = ans; i > ans - 10; i--) {
        cout << arr[i];
    }
    cout << endl;
}

int main() {
    for (int i = 0; i < 100; i++) {
        cin >> num[i];
    }
    init();
    return 0;
}
