#include <iostream>
using namespace std;

int main() {
    // separare declaration for each variable
    float n1, n2, n3;

    cout << "Enter three numbers: ";
    // fixed inputs for n2 and n3, changed dupe n1 to n2
    cin >> n1 >> n2 >> n3;

    // changed logic because why not
    // first if missing ending parathesis and both brackets, and first comparison is not a comparison
    // second if missing ending bracket
    // third if missing starting bracket
    if (n1 >= n2) {
        if (n1 >= n3) {
            cout << "Largest number: " << n1;
        } else {
            cout << "Largest number: " << n3;
        }
    } else if (n2 >= n3) {
        if (n2 >= n3) {
            cout << "Largest number: " << n2;
        } else {
            cout << "Largest number: " << n3;
        }
    } else {
        cout << "Largest number: " << n3;
    }

    return 0;
}
