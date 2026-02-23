#include <iostream>
#include "mathUtils.h"
using namespace std;

int main() {
    int optionSelect = 0;
    do {
        cout << "math menu" << endl;
        cout << "1 ==> add" << endl;
        cout << "2 ==> multiply" << endl; 
        cout << "3 ==> square" << endl;
        cout << "0 ==> exit" << endl;
        cout << "choose an option: ";
        cin >> optionSelect;
        if ((optionSelect < 0) || (optionSelect > 3)) {
            cout << "[invalid option]" << endl;
        } else if (optionSelect == 1) { // add
            int inputA, inputB;
            cout << "enter two munbers: ";
            cin >> inputA >> inputB;
            cout << "result: " << add(inputA, inputB) << endl;
        } else if (optionSelect == 2) { // multiply
            int inputA, inputB;
            cout << "enter two munbers: ";
            cin >> inputA >> inputB;
            cout << "result: " << multiply(inputA, inputB) << endl;
        } else if (optionSelect == 3) { // square
            int inputA;
            cout << "enter a number: ";
            cin >> inputA;
            cout << "result: " << square(inputA) << endl;
        }
    } while (optionSelect != 0);

    return 0;
}