#include <iostream>
#include "FileManager.h"
#include "Validation.h"
using namespace std;

int main() {
    FileManager fm;

    cout << "===== Banking System  =====\n";

    string cname, cpass;
    double cbalance;

    cout << "Enter client name: ";
    getline(cin, cname);
    while (!Validation::validName(cname)) {
        cout << "Invalid name! Try again: ";
        getline(cin, cname);
    }

    cout << "Enter client password: ";
    getline(cin, cpass);
    while (!Validation::validPassword(cpass)) {
        cout << "Invalid password! Try again: ";
        getline(cin, cpass);
    }

    cout << "Enter client balance: ";
    cin >> cbalance;
    while (!Validation::validBalance(cbalance)) {
        cout << "Invalid balance! Try again: ";
        cin >> cbalance;
    }

    Client c1(1, cname, cpass, cbalance);
    fm.addClient(c1);

    Employee e1(2, "John", "emp123", 5000.0);
    fm.addEmployee(e1);

    Admin a1(3, "mohamed", "admin123", 10000.0);
    fm.addAdmin(a1);

    cout << "\nData saved successfully!\n";

    cout << "\n===== Clients in File =====\n";
    vector<Client> clients = fm.getAllClients();
    for (Client c : clients) {
        cout << "ID: " << c.get_id()
             << " | Name: " << c.get_name()
             << " | Balance: " << c.get_balance() << endl;
    }

    cout << "\n===== Employees in File =====\n";
    vector<Employee> employees = fm.getAllEmployees();
    for (Employee e : employees) {
        cout << "ID: " << e.get_id()
             << " | Name: " << e.get_name()
             << " | Salary: " << e.getSalary() << endl;
    }

    // --- Retrieve all admins ---
    cout << "\n===== Admins in File =====\n";
    vector<Admin> admins = fm.getAllAdmins();
    for (Admin a : admins) {
        cout << "ID: " << a.get_id()
             << " | Name: " << a.get_name()
             << " | Salary: " << a.getSalary() << endl;
    }

    return 0;
}
