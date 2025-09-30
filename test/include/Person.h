#pragma once
#include "Validation.h"

class Person
{
protected:
	int id;
	string name;
	string password;

public:
	//Constructors
	Person() {
		id = 0;
	}

	Person(int id, string name, string password) {
		setId(id);
		setName(name);
		setPassword(password);
	}

	// getters
	int getId() {
		return id;
	}

	string getName() {
		return name;
	}

	string getPassword() {
		return password;
	}

	//setters
	void setId(int id) {
		this->id = id;
	}

	void setName(string name) {
		 //validate on name first
		if (Validation::validateName(name)) {
			this->name = name;
		}

	}

	void setPassword(string password) {
		if (Validation::validatePass(password)) {
			this->password = password;
		}
	}

	void display() {
		cout << "id: " << id << endl;
		cout << "name: " << name << endl;
		cout << "password: " << password << endl;
	}

};
