#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    bool hard = false;
    while (A > 0 || B > 0) {
        int a = A % 10;
        int b = B % 10;
        if (a + b > 9) {
            hard = true;
            break;
        }
        A /= 10;
        B /= 10;
    }

    if (hard) cout << "Hard\n";
    else cout << "Easy\n";

    return 0;
}
