#include "Money.h"
#include <iostream>

using namespace std;

int main() { //example main
    Money money1, money2;

    cout << "Enter amount for money 1 (leva stotinki): ";
    cin >> money1;

    cout << "Enter amount for money 2 (leva stotinki): ";
    cin >> money2;

    Money sum = money1 + money2;
    Money difference = money1 - money2;

    cout << "money 1: " << money1 << endl;
    cout << "money 2: " << money2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;

    if (money1 > money2) {
      cout << "money 1 is more" << endl;
    }
    else if (money1 < money2) {
      cout << "levaStotinki is more" << endl;
    }
    else {
      cout << "Equal amounts" << endl;
    }

    Money percentage = 20.0 % money1;
    cout << "20 percent of m = " << percentage << endl;

    return 0;
}