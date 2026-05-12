#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Gacha {
    public:
        string getInfo(string type) { // returns respective info based on type
            if (type == "game") {
                return game;
            } else if (type == "code") {
                return gameCode;
            } else if (type == "currency") {
                return to_string(currency);
            } else if (type == "currencyName") {
                return currencyName;
            } else if (type == "pulls") {
                return pullName + pullPlural;
            } else {
                return "bozo"; // shouldn't happen
            }
        }
        void changeCurrency(string change, double amount) { // add, subtract, or set currency
            if (change == "set") {
                currency = amount;
            } else if (change == "add") {
                currency += amount;
            } else if (change == "subtract") {
                if (amount > currency) {
                    cout << "Invalid: Too Broke" << endl;
                } else {
                    currency -= amount;
                }
            } else {
                cout << "[Invalid change type. Use 'add', 'subtract', or 'set'.]" << endl;
            }
        }
        void printPulls() { // prints pulls in format: "game: currency ==> pulls, remainder currency"
            int pulls = currency / pullCost;
            int remainder = (int)currency % (int)pullCost;
            cout << game << ": " << currency << " " << currencyName << " ==> " << pulls << " " << pullName;
            if (pulls != 1) {
                cout << pullPlural;
            }
            if (remainder > 0) {
                cout << " + " << remainder << " " << currencyName;
            }
            cout << endl;
        }
        void printInfo() { // prints info in format: "game, currency, pulls"
            cout << "Game: " << game << endl;
            cout << "Currency: " << currency << " " << currencyName << endl;
            cout << "Pulls: 1 " << pullName << " costs " << pullCost << " " << currencyName << endl;
        }
    protected:
        string game, gameCode, currencyName, pullName, pullPlural;
        double currency = 0, pullCost;
};

// list of gachas from personal picks and other popular ones
class GSHN: public Gacha {
    public:
        GSHN() {
            game = "Genshin Impact";
            gameCode = "GSHN";
            currencyName = "Primogems";
            pullCost = 160;
            pullName = "Fate";
            pullPlural = "s";
        }
};
class PJSK: public Gacha {
    public:
        PJSK() {
            game = "Project Sekai";
            gameCode = "PJSK";
            currencyName = "Crystals";
            pullCost = 300;
            pullName = "Ticket";
            pullPlural = "s";
        }
};
class LADS: public Gacha {
    public:
        LADS() {
            game = "Love and Deepspace";
            gameCode = "LADS";
            currencyName = "Diamonds";
            pullCost = 150;
            pullName = "Wish";
            pullPlural = "es";
        }
};
class HSR: public Gacha {
    public:
        HSR() {
            game = "Honkai: Star Rail";
            gameCode = "HSR";
            currencyName = "Stellar Jades";
            pullCost = 160;
            pullName = "Pass";
            pullPlural = "es";
        }
};
class ZZZ: public Gacha {
    public:
        ZZZ() {
            game = "Zenless Zone Zero";
            gameCode = "ZZZ";
            currencyName = "Polychrome";
            pullCost = 160;
            pullName = "Tape";
            pullPlural = "s";
        }
};
class WUWA: public Gacha {
    public:
        WUWA() {
            game = "Wuthering Waves";
            gameCode = "WUWA";
            currencyName = "Astrites";
            pullCost = 160;
            pullName = "Tide";
            pullPlural = "s";
        }
};
class ARK: public Gacha {
    public:
        ARK() {
            game = "Arknights";
            gameCode = "ARK";
            currencyName = "Orundum";
            pullCost = 600;
            pullName = "Permit";
            pullPlural = "s";
        }
};
class UMA: public Gacha {
    public:
        UMA() {
            game = "Umamusume: Pretty Derby";
            gameCode = "UMA";
            currencyName = "Carats";
            pullCost = 150;
            pullName = "Scout";
            pullPlural = "s";
        }
};
class NIKKE: public Gacha {
    public:
        NIKKE() {
            game = "NIKKE: Goddess of Victory";
            gameCode = "NIKKE";
            currencyName = "Gems";
            pullCost = 300;
            pullName = "Ticket";
            pullPlural = "s";
        }
};
class PGR: public Gacha {
    public:
        PGR() {
            game = "Punishing: Gray Raven";
            gameCode = "PGR";
            currencyName = "Cards";
            pullCost = 250;
            pullName = "Ticket";
            pullPlural = "s";
        }
};
class NIKKI: public Gacha {
    public:
        NIKKI() {
            game = "Infinity Nikki";
            gameCode = "NIKKI";
            currencyName = "Diamonds";
            pullCost = 120;
            pullName = "Crystal";
            pullPlural = "s";
        }
};
class FGO: public Gacha {
    public:
        FGO() {
            game = "Fate/Grand Order";
            gameCode = "FGO";
            currencyName = "Saint Quartz";
            pullCost = 3;
            pullName = "Ticket";
            pullPlural = "s";
        }
};
class P5X: public Gacha {
    public:
        P5X() {
            game = "Persona 5: The Phantom X";
            gameCode = "P5X";
            currencyName = "Jewels";
            pullCost = 150;
            pullName = "Ticket";
            pullPlural = "s";
        }
};
class HI3: public Gacha {
    public:
        HI3() {
            game = "Honkai Impact 3rd";
            gameCode = "HI3";
            currencyName = "Crystals";
            pullCost = 280;
            pullName = "Card";
            pullPlural = "s";
        }
};
class LBCO: public Gacha {
    public:
        LBCO() {
            game = "Limbus Company";
            gameCode = "LBCO";
            currencyName = "Lunacy";
            pullCost = 130;
            pullName = "Ticket";
            pullPlural = "s";
        }
};

string splitData(string data, bool code){ // takes respective data from account file, true = game, false = amount
    string result = "";
    for (int i = 0; i < data.length(); i++) {
        if (data[i] == '|') {
            if (code) {
                code = false;
            } else {
                code = true;
            }
        } else if (code) {
            result += data[i];
        }
    }
    return result;
}

int main() {
    // evil list of gachas (nasty)
    vector<Gacha*> gachas = {new GSHN(), new PJSK(), new LADS(), new HSR(), new ZZZ(), new WUWA(), new ARK(), new UMA(), new NIKKE(), new PGR(), new NIKKI(), new FGO(), new P5X(), new HI3(), new LBCO()};
    cout << "Welcome to Gacha Wallet Manager!" << endl;
    // user info
    string accountName;
    vector<Gacha*> accountGachas;
    cout << "Enter account name: ";
    cin >> accountName;
    ifstream accountFile(accountName + ".txt");
    if (!accountFile) {
        cout << "[Account not found. Creating new account...]" << endl;
        ofstream newAccount(accountName + ".txt");
        newAccount.close();
    } else {
        cout << "[Account found. Loading data...]" << endl;
        string line;
        do {
            accountFile >> line;
            if (line != "[END]") {
                string gachaCode = splitData(line, true);
                int gachaCurrency = stoi(splitData(line, false));
                for (int i = 0; i < gachas.size(); i++) {
                    if (gachaCode == gachas[i]->getInfo("code")) {
                        accountGachas.push_back(gachas[i]); // add respective gacha to account gachas vector
                        accountGachas.back()->changeCurrency("set", gachaCurrency);
                        break;
                    }
                }
            }
        } while (line != "[END]");
    }
    accountFile.close();
    // main menu
    int menu1;
    do {
        cout << "Loaded Accounts (" << accountGachas.size() << "): " << endl;
        for (int i = 0; i <= accountGachas.size(); i++) {
            if (i != accountGachas.size()) {
                cout << i + 1 << ". " << accountGachas[i]->getInfo("game") << endl;
            } else {
                cout << i + 1 << ". Add new account" << endl;
            }
        }
        cout << "Select which account to manage (0 to save and exit): ";
        cin >> menu1;
        cout << endl;
        if (menu1 < 0 || menu1 > (accountGachas.size() + 1)) {
            cout << "[Invalid selection. Please try again.]" << endl;
        } else if (menu1 == accountGachas.size() + 1) {
            cout << "Available Gachas: " << endl;
            for (int i = 0; i < gachas.size(); i++) {
                cout << i + 1 << ". " << gachas[i]->getInfo("game") << endl;
            }
            cout << "Select a gacha to add (0 to return): ";
            int newGacha;
            cin >> newGacha;
            if (newGacha < 0 || newGacha > gachas.size()) {
                cout << "[Invalid selection. Please try again.]" << endl;
            } else if (newGacha != 0) {
                accountGachas.push_back(gachas[newGacha - 1]);
                cout << "[Account added successfully!]" << endl;
            }
        } else if (menu1 == 0) {
            cout << "[Saving data...]" << endl;
            string saveData = "";
            for (Gacha* info : accountGachas) {
                int tempCurrency = stoi(info->getInfo("currency"));
                saveData += info->getInfo("code") + "|" + to_string(tempCurrency) + "\n";
            }
            ofstream accountFile(accountName + ".txt");
            accountFile << saveData << "[END]";
            accountFile.close();
        } else {
            if (menu1 != 0) {
                // account management menu
                int menu2;
                do {
                    cout << "Managing " << accountGachas[menu1 - 1]->getInfo("game") << " account." << endl;
                    cout << "1. View account info" << endl;
                    cout << "2. Manage " << accountGachas[menu1 - 1]->getInfo("currencyName") << endl;
                    cout << "3. View " << accountGachas[menu1 - 1]->getInfo("pulls") << endl;
                    cout << "Select an option (0 to return): ";
                    cin >> menu2;
                    cout << endl;
                    if (menu2 < 0 || menu2 > 3) {
                        cout << "[Invalid selection. Please try again.]" << endl;
                    } else {
                        if (menu2 == 1) {
                            accountGachas[menu1 - 1]->printInfo();
                        } else if (menu2 == 2) {
                            string changeType;
                            double amount;
                            cout << "Enter change type (add, subtract, set): ";
                            cin >> changeType;
                            cout << "Enter amount: ";
                            cin >> amount;
                            accountGachas[menu1 - 1]->changeCurrency(changeType, amount);
                        } else if (menu2 == 3) {
                            accountGachas[menu1 - 1]->printPulls();
                        }
                    }
                } while (menu2 != 0);
            }
        }
    } while (menu1 != 0);
    
    return 0;
}