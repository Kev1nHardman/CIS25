#include <iostream>
#include <fstream>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string diagnosis;
};

int binarySearch(Patient patients[], int count, int searchId) {
    int left = 0;
    int right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (patients[mid].id == searchId) {
            return mid; // patient found, return index
        } else if (patients[mid].id < searchId) {
            left = mid + 1; // search in the right half
        } else {
            right = mid - 1; // search in the left half
        }
    }
    return -1; // patient not found
}

int main() {
    int menuOption;
    int count = 0;
    Patient patients[100];
    int searchId, index;
    int i = 0;
    do {
        cout << "welcome to c++ hospital patient management system!" << endl;
        cout << "1. add patient" << endl;
        cout << "2. display patients" << endl;
        cout << "3. search patient" << endl;
        cout << "4, update patient" << endl;
        cout << "5. save patients" << endl;
        cout << "6. exit" << endl;
        cout << "please enter your menu option: ";
        cin >> menuOption;
        switch (menuOption) {
            case 1: // add patient
                if (count < 100) {
                    cout << "enter patient id: ";
                    cin >> patients[count].id;
                    cout << "enter patient name: ";
                    cin >> patients[count].name;
                    cout << "enter patient age: ";
                    cin >> patients[count].age;
                    cout << "enter patient gender: ";
                    cin >> patients[count].gender;
                    cout << "enter patient diagnosis: ";
                    cin >> patients[count].diagnosis;
                    count++;
                } else {
                    cout << "maximum patient capacity reached!" << endl;
                }
                break;
            case 2: // display patients
                for (i = 0; i < count; i++) {
                    cout << "patient #" << i + 1 << ":" << endl;
                    cout << "patient id: " << patients[i].id << endl;
                    cout << "patient name: " << patients[i].name << endl;
                    cout << "patient age: " << patients[i].age << endl;
                    cout << "patient gender: " << patients[i].gender << endl;
                    cout << "patient diagnosis: " << patients[i].diagnosis << endl;
                }
                break;
            case 3: // search patient
                cout << "enter patient id to search: ";
                cin >> searchId;
                index = binarySearch(patients, count, searchId);
                if (index != -1) {
                    cout << "patient found!" << endl;
                    cout << "patient name: " << patients[index].name << endl;
                    cout << "patient age: " << patients[index].age << endl;
                    cout << "patient gender: " << patients[index].gender << endl;
                    cout << "patient diagnosis: " << patients[index].diagnosis << endl;
                } else {
                    cout << "patient not found." << endl;
                }
                break;
            case 4: // update patient
                cout << "enter patient id to update: ";
                cin >> searchId;
                index = binarySearch(patients, count, searchId);
                if (index != -1) {
                    cout << "patient found!" << endl;
                    cout << "enter new patient diagnosis: ";
                    cin >> patients[index].diagnosis;
                } else {
                    cout << "patient not found." << endl;
                }
                break;
            case 5: // save patients
                ofstream patientList("patients.txt");
                for (i = 0; i < count; i++) {
                    patientList << patients[i].id << "," << patients[i].name << "," << patients[i].age << "," << patients[i].gender << "," << patients[i].diagnosis << endl;
                }
                patientList.close();
                cout << "patients saved to patients.txt" << endl;
                break;
        }
    } while (menuOption != 6);

    return 0;
}