#include <iostream>
using namespace std;

// ---------------- Modular Exponentiation ----------------
int modPow(int base, int exp, int mod) {
    int result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

// ---------------- RSA Functions ----------------
int rsaEncrypt(int m, int e, int n) {
    return modPow(m, e, n);
}

int rsaDecrypt(int c, int d, int n) {
    return modPow(c, d, n);
}

// ---------------- Caesar Cipher ----------------
int caesarEncrypt(int msg, int key) {
    return (msg + key) % 26;
}

int caesarDecrypt(int cipher, int key) {
    return (cipher - key + 26) % 26;
}

// ---------------- MAIN ----------------
int main() {

    // -------------------- SENDER KEYS --------------------
    int pS = 3, qS = 5;
    int nS = pS * qS;                 // 15
    int phiS = (pS - 1) * (qS - 1);   // 8
    int eS = 3;                       // sender public key
    int dS = 3;                       // sender private key

    // -------------------- RECEIVER KEYS --------------------
    int pR = 5, qR = 7;
    int nR = pR * qR;                 // 35
    int phiR = (pR - 1) * (qR - 1);   // 24
    int eR = 5;                       // receiver public key
    int dR = 29;                      // receiver private key

    // -------------------- SENDER SIDE --------------------
    int symKey = 3;  // symmetric key < nR
    cout << "Sender: Symmetric Key = " << symKey << endl;

    // Encrypt symmetric key with receiver's public key
    int encKey = rsaEncrypt(symKey, eR, nR);
    cout << "Sender: Encrypted Key Sent = " << encKey << endl;

    // Message to send
    int msg = 2;
    cout << "Sender: Plain Message = " << msg << endl;

    // Encrypt message using Caesar cipher
    int cipherMsg = caesarEncrypt(msg, symKey);
    cout << "Sender: Cipher Text = " << cipherMsg << endl;

    // Sign message using sender private key
    int signature = rsaEncrypt(msg, dS, nS);
    cout << "Sender: Signature = " << signature << endl;

    // -------------------- RECEIVER SIDE --------------------
    // Decrypt symmetric key
    int decKey = rsaDecrypt(encKey, dR, nR);
    cout << "Receiver: Decrypted Symmetric Key = " << decKey << endl;

    // Decrypt message
    int decryptedMsg = caesarDecrypt(cipherMsg, decKey);
    cout << "Receiver: Decrypted Message = " << decryptedMsg << endl;

    // Verify signature
    int verifySig = rsaDecrypt(signature, eS, nS);
    cout << "Receiver: Signature Verifies To = " << verifySig << endl;

    if (verifySig == msg)
        cout << "Signature Verified ✓" << endl;
    else
        cout << "Signature Failed ✗" << endl;

    return 0;
}
