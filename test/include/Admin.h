#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"
#include <iostream>
using namespace std;

class Admin : public Employee {
public:
    Admin(int i=0, string n="", string p="", double s=0)
        : Employee(i, n, p, s) {}

    void display() const {
        cout << "Admin ID: " << get_id()
             << "\nName: " << get_name()
             << "\nSalary: " << getSalary() << "\n";
    }
};

#endif
