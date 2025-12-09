#include <iostream>
using namespace std;

int main() {
    int x = -1;

    int is_old = 0;
    int is_even = 0;

    while (x != 0) {
        cout << "Enter an integer: ";
        cin >> x;
        if (x == 0) {
            break;
        }
        if (x % 2 == 0) {
            is_even += 1;
        } else {
            is_old += 1;
        }
    }

    cout << "#Even numbers = " << is_even << endl;
    cout << "#Odd numbers = " << is_old << endl;
    return 0;
}
