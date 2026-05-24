#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void prod() {
    int x, y, z;
    bool valid = false;

    x = rand() % 13;
    y = rand() % 13;

    for (int i = 1; i <= 3; i++) {
        cout << x << " * " << y << " = ";
        cin >> z;

        if (z == (x * y)) {
            cout << "Well guessed the answer is correct" << endl;
            valid = true;
            break;
        } else {
            cout << "Wrong answer" << endl;
        }
    }

    if (!valid) {
        cout << "The correct answer is: " << (x * y) << endl;
    }
}

int main() {

    srand(time(0));

    cout << "========================================" << endl;
    cout << "Developer: Omar Hafez Khalil" << endl;
    cout << "Location: Giza - Daraa" << endl;
    cout << "Project: Multiplication Game" << endl;
    cout << "========================================" << endl << endl;

    char input;

    do {
        prod();

        cout << "To play again press any key/number, to exit press (0): ";
        cin >> input;
        cout << "----------------------------------------" << endl;

    } while (input != '0');

    cout << "Thank you for playing! Goodbye." << endl;

    system("pause");
    return 0;
}
