#include <iostream>
using namespace std;

// Simple gcd
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Simple modular exponentiation: (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;

    for (long long i = 0; i < exp; i++) {
        res = (res * base) % mod;
    }
    return res;
}

// Find modular inverse of e mod phi by brute force
long long modInverse(long long e, long long phi) {
    for (long long d = 1; d < phi; d++) {
        if ((e * d) % phi == 1)
            return d;
    }
    return -1;  // not found
}

int main() {
    long long p, q, e, m;

    cout << "=== Simple RSA Demo (Toy) ===\n";

    // 1. Input two primes p and q
    cout << "Enter prime p: ";
    cin >> p;
    cout << "Enter prime q: ";
    cin >> q;

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    cout << "n = p * q = " << n << endl;
    cout << "phi(n) = (p-1)*(q-1) = " << phi << endl;

    // 2. Input e such that 1 < e < phi and gcd(e, phi) = 1
    cout << "Enter public exponent e (coprime with phi): ";
    cin >> e;

    if (gcd(e, phi) != 1) {
        cout << "e is not coprime with phi. Choose different e.\n";
        return 0;
    }

    // 3. Compute d = e^{-1} mod phi
    long long d = modInverse(e, phi);
    if (d == -1) {
        cout << "No modular inverse found. Try different e.\n";
        return 0;
    }

    cout << "\nPublic key  (e, n) = (" << e << ", " << n << ")\n";
    cout << "Private key (d, n) = (" << d << ", " << n << ")\n";

    // 4. Input message m
    cout << "\nEnter message m (as number, m < n): ";
    cin >> m;

    if (m >= n) {
        cout << "Message must be less than n.\n";
        return 0;
    }

    // 5. Encryption: c = m^e mod n
    long long c = power(m, e, n);
    cout << "Encrypted ciphertext c = " << c << endl;

    // 6. Decryption: m' = c^d mod n
    long long m_dec = power(c, d, n);
    cout << "Decrypted message m' = " << m_dec << endl;

    return 0;
}
