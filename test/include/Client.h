#pragma once
#include "Person.h"
#include<vector>
#include<iterator>
class Client: public Person
{
private:
	double balance;
public:
	Client() : Person(){
		balance = 0;
	}
	Client(int id, string name, string password, double balance) : Person(id, name, password) {
		setBalance(balance);
	}

	double getBalance() {
		return balance;
	}

	void setBalance(double balance) {
		if (Validation::validateBalance(balance)) {
			this->balance = balance;
		}
	}

	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "Success deposit" << endl;
		}
		else {
			cout << "minmum amount is 1EGY" << endl;
		}
	}
	void withdraw(double amount) {
		if (amount <= balance) {
			balance -= amount;
			cout << "Success withdraw" << endl;
		}
		else {
			cout << "Amount exceeded balance" << endl;
		}
	}
	void transferTo(double amount, Client& recipient) {
		// withdrow
		if (amount <= balance) {
			balance -= amount;
			//deposit for  recipient
			if (amount > 0) {
				recipient.balance += amount;
				cout << "Success transfer" << endl;
			}
			else {
				cout << "Minmum amount is 1EGY" << endl;
			}
		}
		else {
			cout << "Amount exceeded balance" << endl;
		}


	}

	void checkBalance() {
		cout << "Balance: " << getBalance() << endl;
	}

	void display() {
		Person::display();
		cout << "Balance: " << balance << endl;
		cout << "\n===============\n" << endl;
	}
};

static vector<Client> allClients;

static vector<Client>::iterator cIt;
