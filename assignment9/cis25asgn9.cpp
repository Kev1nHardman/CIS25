#include <iostream>
using namespace std;

class User {
    public:
        string name;
        int id;
        virtual string accessLevel() {
            access = "None";
            return access;
        }
        void setPassword(string pwd) {
            password = pwd;
        }
        bool checkPassword(string input) {
            return input == password;
        }
    protected:
        string access, password;
};

class Employee : public User {
    public:
        string accessLevel() override {
            access = "View";
            return access;
        }
};

class Manager : public Employee {
    public:
        string accessLevel() override {
            access = "View,Update";
            return access;
        }
};

class Admin : public Manager {
    public:
        string accessLevel() override {
            access = "View,Update,Add,Delete";
            return access;
        }
};

class InventoryItem {
    public:
        string name;
        int quantity;
};

int main() {
    // user related stuff
    User users[100];
    int userCount = 0;
    Employee employees[50];
    int employeeCount = 0;
    Manager managers[20];
    int managerCount = 0;
    Admin admins[5];
    int adminCount = 0;
    // inventory related stuff
    InventoryItem inventory[100];
    int inventoryCount = 0;
    // menu time
    int menuOption;
    do {
        cout << "welcome to c++ inventory management system!" << endl;
        cout << "1. display users" << endl;
        cout << "2. add user" << endl;
        cout << "3. remove user" << endl;
        cout << "4. display inventory" << endl;
        cout << "5. update inventory" << endl;
        cout << "6. add inventory item" << endl;
        cout << "7. remove inventory item" << endl;
        cout << "8. exit" << endl;
        cout << "please enter your menu option: ";
        cin >> menuOption;
        if (menuOption == 1) { // display users
            if (userCount == 0) {
                cout << "no users to display" << endl;
            } else {
                for (int i = 0; i < userCount; i++) {
                    cout << "user #" << i + 1 << ": " << users[i].name << endl;
                }
            }
            if (employeeCount == 0) {
                cout << "no employees to display" << endl;
            } else {
                for (int i = 0; i < employeeCount; i++) {
                    cout << "employee #" << i + 1 << ": " << employees[i].name << endl;
                }
            }
            if (managerCount == 0) {
                cout << "no managers to display" << endl;
            } else {
                for (int i = 0; i < managerCount; i++) {
                    cout << "manager #" << i + 1 << ": " << managers[i].name << endl;
                }
            }
            if (adminCount == 0) {
                cout << "no admins to display" << endl;
            } else {
                for (int i = 0; i < adminCount; i++) {
                    cout << "admin #" << i + 1 << ": " << admins[i].name << endl;
                }
            }
        } else if (menuOption == 2) { // add user
            string accessInput;
            cout << "what access level? (user, employee, manager, admin): ";
            cin >> accessInput;
            if (accessInput == "user") {
                if (userCount < 100) {
                    cout << "enter name: ";
                    cin >> users[userCount].name;
                    cout << "enter id: ";
                    cin >> users[userCount].id;
                    cout << "enter password: ";
                    string pwd;
                    cin >> pwd;
                    users[userCount].setPassword(pwd);
                    userCount++;
                } else {
                    cout << "maximum user capacity reached!" << endl;
                }
            } else if (accessInput == "employee") {
                if (employeeCount < 50) {
                    cout << "enter name: ";
                    cin >> employees[employeeCount].name;
                    cout << "enter id: ";
                    cin >> employees[employeeCount].id;
                    cout << "enter password: ";
                    string pwd;
                    cin >> pwd;
                    employees[employeeCount].setPassword(pwd);
                    employeeCount++;
                } else {
                    cout << "maximum employee capacity reached!" << endl;
                }
            } else if (accessInput == "manager") {
                if (managerCount < 20) {
                    cout << "enter name: ";
                    cin >> managers[managerCount].name;
                    cout << "enter id: ";
                    cin >> managers[managerCount].id;
                    cout << "enter password: ";
                    string pwd;
                    cin >> pwd;
                    managers[managerCount].setPassword(pwd);
                    managerCount++;
                } else {
                    cout << "maximum manager capacity reached!" << endl;
                }
            } else if (accessInput == "admin") {
                if (adminCount < 5) {
                    cout << "enter name: ";
                    cin >> admins[adminCount].name;
                    cout << "enter id: ";
                    cin >> admins[adminCount].id;
                    cout << "enter password: ";
                    string pwd;
                    cin >> pwd;
                    admins[adminCount].setPassword(pwd);
                    adminCount++;
                } else {
                    cout << "maximum admin capacity reached!" << endl;
                }
            } else {
                cout << "invalid access level, please try again!" << endl;
            }
        } else if (menuOption == 3) { // remove user
            cout << "tbh might've cooked too hard so this is gonna be uninplimented" << endl;
        } else if (menuOption == 4) { // display inventory
            cout << "enter your id: ";
            int id;
            cin >> id;
            bool found = false;
            string pwd;
            for (int i = 0; i < employeeCount; i++) {
                if (employees[i].id == id) {
                    cout << "enter your password: ";
                    cin >> pwd;
                    if (employees[i].checkPassword(pwd)) {
                        found = true;
                    } else {
                        cout << "incorrect password, access denied!" << endl;
                    }
                    break;
                }
            }
            if (!found) {
                for (int i = 0; i < managerCount; i++) {
                    if (managers[i].id == id) {
                        cout << "enter your password: ";
                        cin >> pwd;
                        if (managers[i].checkPassword(pwd)) {
                            found = true;
                        } else {
                            cout << "incorrect password, access denied!" << endl;
                        }
                        break;
                    }
                }
            }
            if (!found) {
                for (int i = 0; i < adminCount; i++) {
                    if (admins[i].id == id) {
                        cout << "enter your password: ";
                        cin >> pwd;
                        if (admins[i].checkPassword(pwd)) {
                            found = true;
                        } else {
                            cout << "incorrect password, access denied!" << endl;
                        }
                        break;
                    }
                }
            }
            if (found) {
                if (inventoryCount == 0) {
                    cout << "no inventory items to display" << endl;
                } else {
                    for (int i = 0; i < inventoryCount; i++) {
                        cout << "item #" << i + 1 << ": " << inventory[i].name << " (quantity: " << inventory[i].quantity << ")" << endl;
                    }
                }
            }
        } else if (menuOption == 5) { // update inventory
            cout << "enter your id: ";
            int id;
            cin >> id;
            bool found = false;
            string pwd;
            for (int i = 0; i < managerCount; i++) {
                if (managers[i].id == id) {
                    cout << "enter your password: ";
                    cin >> pwd;
                    if (managers[i].checkPassword(pwd)) {
                        found = true;
                    } else {
                        cout << "incorrect password, access denied!" << endl;
                    }
                    break;
                }
            }
            if (!found) {
                for (int i = 0; i < adminCount; i++) {
                    if (admins[i].id == id) {
                        cout << "enter your password: ";
                        cin >> pwd;
                        if (admins[i].checkPassword(pwd)) {
                            found = true;
                        } else {
                            cout << "incorrect password, access denied!" << endl;
                        }
                        break;
                    }
                }
            }
            if (found) {
                cout << "enter item name to update: ";
                string itemName;
                cin >> itemName;
                int index = -1;
                for (int i = 0; i < inventoryCount; i++) {
                    if (inventory[i].name == itemName) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    cout << "enter new quantity: ";
                    int newQuantity;
                    cin >> newQuantity;
                    inventory[index].quantity = newQuantity;
                    cout << "inventory updated!" << endl;
                } else {
                    cout << "item not found." << endl;
                }
            }
        } else if (menuOption == 6) { // add inventory item
            cout << "enter your id: ";
            int id;
            cin >> id;
            bool found = false;
            string pwd;
            for (int i = 0; i < adminCount; i++) {
                if (admins[i].id == id) {
                    cout << "enter your password: ";
                    cin >> pwd;
                    if (admins[i].checkPassword(pwd)) {
                        found = true;
                    } else {
                        cout << "incorrect password, access denied!" << endl;
                    }
                    break;
                }
            }
            if (found) {
                if (inventoryCount < 100) {
                    cout << "enter item name: ";
                    cin >> inventory[inventoryCount].name;
                    cout << "enter item quantity: ";
                    cin >> inventory[inventoryCount].quantity;
                    inventoryCount++;
                    cout << "inventory item added!" << endl;
                } else {
                    cout << "maximum inventory capacity reached!" << endl;
                }
            }
        } else if (menuOption == 7) { // remove inventory item
            cout << "enter your id: ";
            int id;
            cin >> id;
            bool found = false;
            string pwd;
            for (int i = 0; i < adminCount; i++) {
                if (admins[i].id == id) {
                    cout << "enter your password: ";
                    cin >> pwd;
                    if (admins[i].checkPassword(pwd)) {
                        found = true;
                    } else {
                        cout << "incorrect password, access denied!" << endl;
                    }
                    break;
                }
            }
            if (found) {
                cout << "enter item name to remove: ";
                string itemName;
                cin >> itemName;
                int index = -1;
                for (int i = 0; i < inventoryCount; i++) {
                    if (inventory[i].name == itemName) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    for (int i = index; i < inventoryCount - 1; i++) {
                        inventory[i] = inventory[i + 1];
                    }
                    inventoryCount--;
                    cout << "inventory item removed!" << endl;
                } else {
                    cout << "item not found." << endl;
                }
            }
        } else if (menuOption == 8) { // exit
            cout << "goodbye!" << endl;
        } else {
            cout << "invalid menu option, please try again!" << endl;
        }
    } while (menuOption != 8);

    return 0;
}
