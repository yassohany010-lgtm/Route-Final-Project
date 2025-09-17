#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
    string password;

public:
    int get_id() const { return id; }
    string get_name() const { return name; }
    string get_password() const { return password; }

    void set_id(int i) { id = i; }
    void set_name(const string& n) { name = n; }
    void set_password(const string& p) { password = p; }
};

#endif
