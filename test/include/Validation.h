#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <string>
using namespace std;

class Validation {
public:
    static bool validName(const string& name) {
        if (name.length() < 5 || name.length() > 20) {
            return false;
        }
        for (size_t i = 0; i < name.length(); i++) {
            if (!isalpha(name[i]))
                return false;
        }
        return true;
    }

    static bool validPassword(const string& password) {
        if (password.length() < 8 || password.length() > 20) {
            return false;
        }
        return true;
    }

    static bool validBalance(double balance) {
        return balance >= 1500;
    }

    static bool validSalary(double salary) {
        return salary >= 5000;
    }
};

#endif
