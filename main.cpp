#include <iostream>
#include <string>
#include <fstream>
using namespace std;


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
