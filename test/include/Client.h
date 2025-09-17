#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include <iostream>
using namespace std;

class Client : public Person {
private:
    double balance;

public:
    Client(int i=0, string n="", string p="", double b=0) {
        id = i; name = n; password = p; balance = b;
    }

    double get_balance() const { return balance; }
    void set_balance(double b) { balance = b; }

    void display() const {
        cout << "Client ID: " << id << "\nName: " << name
             << "\nBalance: " << balance << "\n";
    }
};

#endif
