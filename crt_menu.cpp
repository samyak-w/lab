#include <iostream>
using namespace std;

// Very simple modular inverse using brute-force method
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // inverse does not exist
}

int main() {
    int a1, m1, a2, m2, a3, m3;

    cout << "=== Chinese Remainder Theorem (3 Equations) ===\n";

    cout << "Enter a1 and m1: ";
    cin >> a1 >> m1;

    cout << "Enter a2 and m2: ";
    cin >> a2 >> m2;

    cout << "Enter a3 and m3: ";
    cin >> a3 >> m3;

    // Product of all moduli
    int M = m1 * m2 * m3;

    // M1, M2, M3
    int M1 = M / m1;
    int M2 = M / m2;
    int M3 = M / m3;

    // Modular inverses
    int y1 = modInverse(M1 % m1, m1);
    int y2 = modInverse(M2 % m2, m2);
    int y3 = modInverse(M3 % m3, m3);

    if (y1 == -1 || y2 == -1 || y3 == -1) {
        cout << "Modular inverse does not exist. Moduli may not be coprime.";
        return 0;
    }

    // Apply CRT formula
    int x = (a1 * M1 * y1 +
             a2 * M2 * y2 +
             a3 * M3 * y3) % M;

    if (x < 0) x += M;

    cout << "\nSolution: x = " << x << " (mod " << M << ")";
    return 0;
}
