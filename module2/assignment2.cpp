#include <iostream>
using namespace std;

int main() {
    string itemName;
    int itemAmount;
    float itemPrice;

    cout << "Enter item name: ";
    cin >> itemName;
    cout << "Enter item amount: ";
    cin >> itemAmount;
    cout << "Enter item price: ";
    cin >> itemPrice;

    cout << "Total cost for " << itemName << ": $" << (itemAmount * itemPrice) << endl;

    return 0;
}
