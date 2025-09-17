#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <iostream>
using namespace std;

class Employee : public Person {
private:
    double salary;

public:
    Employee(int i=0, string n="", string p="", double s=0) {
        id = i; name = n; password = p; salary = s;
    }

    double getSalary() const { return salary; }
    void setSalary(double s) { salary = s; }

    void display() const {
        cout << "Employee ID: " << id << "\nName: " << name
             << "\nSalary: " << salary << "\n";
    }
};

#endif
