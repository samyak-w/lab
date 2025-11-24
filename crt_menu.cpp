#include <iostream>
using namespace std;

// simple modular inverse using brute force
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; 
}

int main() {
    int a1, m1, a2, m2;
    cout << "Solve system: x ≡ a (mod m)" << endl;

    cout << "Enter a1 and m1: ";
    cin >> a1 >> m1;

    cout << "Enter a2 and m2: ";
    cin >> a2 >> m2;

    int M = m1 * m2;
    int M1 = M / m1;
    int M2 = M / m2;

    int y1 = modInverse(M1 % m1, m1);
    int y2 = modInverse(M2 % m2, m2);

    int x = (a1 * M1 * y1 + a2 * M2 * y2) % M;

    cout << "x = " << x << " (mod " << M << ")";
    return 0;
}
