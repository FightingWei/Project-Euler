#include <iostream>
#define max_n 1000000
using namespace std;

int num[11] = {0, 1};
int num2[11] = {0};

int main() { 
    for (int i = 2; i <= 10; i++) {
        num[i] = num[i - 1] * i;
        cout << num[i] << endl;
    }
    for (int i = )
    int k = 1;
    int sum = 0;
    for (int i = 10; i >= 1; i--) {
        for (int j = 1; j <= 10; j++) {
            sum += num[i - 1] * j;
            if (sum > max_n) {
                num2[k] = (j - 1) % 10;
                sum -= num[i] * j;
                k++;
                break;
            }
            num2[k] = 0;
            k++;
        }
    }
    for (int i = 1; i <= 10; i++) {
        cout << num2[i];
    }
    cout << endl;
    return 0;
}
