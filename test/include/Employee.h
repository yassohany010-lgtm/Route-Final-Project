#pragma once
#include "Person.h"
#include"Client.h"
class Employee : public Person
{
protected:
	double salary;
public:
	Employee() : Person() {
		salary = 0;
	}

	Employee(int id, string name, string password, double salary) : Person(id, name, password) {
		setSalary(salary);
	}

	// getters
	double getSalary() {
		return this->salary;
	}

	//setters
	void setSalary(double salary) {
		if (Validation::validateSalary(salary)) {
			this->salary = salary;
		}
	}

	void display() {
		Person::display();
		cout << "Salary: " << salary << endl;
		cout << "\n===============\n" << endl;
	}


	void addClient(Client& client) {
		allClients.push_back(client);
	}

	Client* searchClient(int id) {

		for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {
			if (cIt->getId() == id) return cIt._Ptr;
		}
		return nullptr;
	}

	void listClient() {
		for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {
			cIt->display();
		}
	}

	void editClient(Client* client, string name, string password, double balance) {
		//Client* client = searchClient(id);
		client->setName(name);
		client->setPassword(password);
		client->setBalance(balance);
	}

};


static vector<Employee> allEmployees;

static vector<Employee>::iterator eIt;
