#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class Parser {
public:
    static vector<string> split(const string& line) {
        vector<string> result;
        stringstream ss(line);
        string item;
        while (getline(ss, item, ',')) {
            result.push_back(item);
        }
        return result;
    }

    static Client parseToClient(const string& line) {
        vector<string> t = split(line);
        return Client(stoi(t[0]), t[1], t[2], stod(t[3]));
    }

    static Employee parseToEmployee(const string& line) {
        vector<string> t = split(line);
        return Employee(stoi(t[0]), t[1], t[2], stod(t[3]));
    }

    static Admin parseToAdmin(const string& line) {
        vector<string> t = split(line);
        return Admin(stoi(t[0]), t[1], t[2], stod(t[3]));
    }
};

#endif
