#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

class Client{
    private:
        string name;
        int account_number;
        float balance;
    public:
        Client(string name, int account_number, float balance){
            this->name = name;
            this->account_number = account_number;
            this->balance = balance;
        }
        void deposit(float amount){
            balance += amount;
            cout << "Deposited " << amount << " to " << name << "'s account" << endl;
        };
        void withdraw(float amount){
            if(balance >= amount){
                balance -= amount;
                cout << "Withdrawn " << amount << " from " << name << "'s account" << endl;
            }else{
                cout << "Insufficient balance" << endl;
            }
        }
};


int main(){
    int action = 0;
    unordered_map<string, Client> clients;
    string name, accountName;
    int account_number;
    float balance, amount;

    while (action != 4) {
        cout << "What actions would you like to do?" << endl;
        cout << "1 for Make an Account, 2 for Deposit, 3 for Withdraw, 4 to end" << endl;
        cin >> action;

        switch (action) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter account number: ";
                cin >> account_number;
                cout << "Enter balance: ";
                cin >> balance;
                cout << "Enter account name: ";
                cin >> accountName;
                clients.emplace(accountName, Client(name, account_number, balance));
                break;
            default:
                cout << "Invalid action" << endl;
                break;
        }
    }
    return 0;
}