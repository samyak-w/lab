#include <iostream>
using namespace std;

// Compute modular inverse using Extended Euclidean Algorithm
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;   // quotient

        t = m;
        m = a % m;   // m = remainder
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to compute x using CRT
int crt(int rem[], int mod[], int n) {
    int prod = 1;
    for (int i = 0; i < n; i++)
        prod *= mod[i];

    int result = 0;
    for (int i = 0; i < n; i++) {
        int pp = prod / mod[i];
        result += rem[i] * pp * modInverse(pp, mod[i]);
    }
    return result % prod;
}

int main() {
    int rem[] = {2, 3, 2};
    int mod[] = {3, 5, 7};
    int n = 3;

    cout << "Solution x = " << crt(rem, mod, n) << endl; // Output: 23

    return 0;
}
