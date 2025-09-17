#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "DataSourceInterface.h"
#include "FilesHelper.h"
#include "Parser.h"

class FileManager : public DataSourceInterface {
private:
    string clientsFile = "clients.txt";
    string employeesFile = "employees.txt";
    string adminsFile = "admins.txt";

public:
    void addClient(Client c) override {
        string line = to_string(c.get_id()) + "," + c.get_name() + "," +
                      c.get_password() + "," + to_string(c.get_balance());
        FilesHelper::saveLine(clientsFile, line);
    }

    void addEmployee(Employee e) override {
        string line = to_string(e.get_id()) + "," + e.get_name() + "," +
                      e.get_password() + "," + to_string(e.getSalary());
        FilesHelper::saveLine(employeesFile, line);
    }

    void addAdmin(Admin a) override {
        string line = to_string(a.get_id()) + "," + a.get_name() + "," +
                      a.get_password() + "," + to_string(a.getSalary());
        FilesHelper::saveLine(adminsFile, line);
    }

    vector<Client> getAllClients() override {
        vector<Client> clients;
        for (string line : FilesHelper::readFile(clientsFile)) {
            clients.push_back(Parser::parseToClient(line));
        }
        return clients;
    }

    vector<Employee> getAllEmployees() override {
        vector<Employee> employees;
        for (string line : FilesHelper::readFile(employeesFile)) {
            employees.push_back(Parser::parseToEmployee(line));
        }
        return employees;
    }

    vector<Admin> getAllAdmins() override {
        vector<Admin> admins;
        for (string line : FilesHelper::readFile(adminsFile)) {
            admins.push_back(Parser::parseToAdmin(line));
        }
        return admins;
    }

    void removeAllClients() override {
        FilesHelper::clearFile(clientsFile);
    }

    void removeAllEmployees() override {
        FilesHelper::clearFile(employeesFile);
    }

    void removeAllAdmins() override {
        FilesHelper::clearFile(adminsFile);
    }
};

#endif
