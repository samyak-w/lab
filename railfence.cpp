#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    int key;
    
    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter key (rails): ";
    cin >> key;

    string rails[key];
    int row = 0, dir = 1;  // dir = +1 down, -1 up

    for (char c : text) {
        rails[row] += c;

        if (row == 0) dir = 1;
        else if (row == key - 1) dir = -1;

        row += dir;
    }

    string cipher = "";
    for (int i = 0; i < key; i++)
        cipher += rails[i];

    cout << "Cipher = " << cipher;
    return 0;
}
