#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool paymentProcess(string cardNumber, double balance, double amount, bool accountValid) {
    if (cardNumber.length() != 16) {
        cout << "Invalid Card\n";
        return false;
    }
    if (balance < amount) {
        cout << "Insufficient Funds\n";
        return false;
    }
    if (!accountValid) {
        cout << "Invalid Account\n";
        return false;
    }
    cout << "Payment Successful\n";
    return true;
}
void completeTransaction(string customerName, string cardNumber, double amount) {
    cout << "Customer: " << customerName << " charged $" << amount << endl;
    cout << "Transaction Saved\n";
    cout << "Statement Sent\n";

    ofstream file("database.csv", ios::app);
    if (file.is_open()) {
        file << customerName << "," << cardNumber << "," << amount << "\n";
        file.close();
    } else {
        cout << "Error opening database.csv\n";
    }
}

int main() {
    string customerName, cardNumber;
    double balance, amount;
    bool accountValid;

    cout << "Enter customer name: ";
    getline(cin, customerName);

    cout << "Enter 16-digit card number: ";
    cin >> cardNumber;

    cout << "Enter account balance: ";
    cin >> balance;

    cout << "Enter purchase amount: ";
    cin >> amount;

    cout << "Is account valid? (1=Yes,0=No): ";
    cin >> accountValid;

    if (paymentProcess(cardNumber, balance, amount, accountValid)) {
        completeTransaction(customerName, cardNumber, amount);
    } else {
        cout << "Transaction Failed\n";
    }

    return 0;
}
