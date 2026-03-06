#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Item {
    public:
        string name;
        double price;
        int quantity;
        double getTotalPrice() {
            return price * quantity;
        }
};

int main() {
    int menuOption;
    cout << fixed << setprecision(2);
    do {
        cout << "===== SHOPPING CART MENU =====" << endl;
        cout << "1. add item to cart" << endl;
        cout << "2. view checkout" << endl;
        cout << "3. exit" << endl;
        cout << "choose an option: ";
        cin >> menuOption;
        if(menuOption < 1 || menuOption > 3) {
            cout << "invalid option" << endl;
        } else if(menuOption == 1) {
            Item item;
            cout << "enter item name: ";
            cin >> item.name;
            cout << "enter item price: ";
            cin >> item.price;
            cout << "enter item quantity: ";
            cin >> item.quantity;
            // add to cart.txt
            fstream cart("cart.txt", std::ios::app);
            cart << item.name << "," << item.price << "," << item.quantity << endl;
            cart.close();
        } else if(menuOption == 2) {
            string cartItem;
            double totalPrice = 0;
            cout << "===== CHECKOUT =====" << endl;
            ifstream cart("cart.txt");
            while(getline(cart, cartItem)) { // read cart.txt line by line
                int index = 0;
                string itemName = "";
                for(; cartItem[index] != ','; index++) { // read until first comma (item)
                    itemName += cartItem[index];
                }
                cout << itemName << " - $";
                index++; // skip the comma
                string tempNum = "";
                for(; cartItem[index] != ','; index++) { // read until second comma (price)
                    tempNum += cartItem[index];
                }
                double itemPrice = stod(tempNum);
                cout << itemPrice << " x ";
                index++; // skip the comma
                tempNum = "";
                for(; index < cartItem.length(); index++) { // read until end (quantity)
                    tempNum += cartItem[index];
                }
                int itemQuantity = stoi(tempNum);
                totalPrice += itemPrice * itemQuantity;
                cout << itemQuantity << " = $" << itemPrice * itemQuantity << endl;
            }
            cart.close();
            cout << "--------------------" << endl;
            cout << "total: $" << totalPrice << endl;
        } else if(menuOption == 3) {
            cout << "thank you for shopping!";
        }
    } while (menuOption != 3);

    return 0;
}