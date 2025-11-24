#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    cout << "GCD = " << a;
    return 0;
}
