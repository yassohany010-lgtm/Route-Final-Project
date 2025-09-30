#pragma once
#include<iostream>
#include<string>
#include<limits>
using namespace std;
class Validation
{
public:
	static bool validateName( string name ) {
		if (!(name.size() >= 3 && name.size() <= 20)) {
			cout << "min size 3 and max size 20!" << endl;
			return false;
		}
		for (int i = 0; i < name.size(); i++) {
			if (!isalpha(name[i])) {
				cout << "the name must be alphabetic chars without spaces!" << endl;
				return false;
			}
		}
		return true;
	}

	static bool validatePass(string pass) {
		if (!(pass.size() >= 8 && pass.size() <= 20)) {
			cout << "Password must be with min size 8 and max size 20!" <<endl;
			return false;
		}
		for (int i = 0; i < pass.size(); i++) {
			if (pass[i] == ' ') {
				cout << "Password must be without spaces!" << endl;
				return false;
			}
		}
		return true;
	}

	static bool validateBalance(double balance) {
		return balance >= 1500;
	}

	static bool validateSalary(double salary) {
		return salary >= 5000;
	}

	static string enterName(string msg) {
		string name;
		do {
			cout << msg;
			getline(cin, name);
		} while (!validateName(name));
		return name;
	}
	static string enterPassword(string msg) {
		string pass;
		do {
			cout << msg;
			getline(cin, pass);
		} while (!validatePass(pass));
		return pass;
	}
	static double enterBalance(string msg) {
		double balance;
		do {
			cout << msg;
			cin >> balance;
		} while (!validateBalance(balance));
		return balance;
	}
	static double enterSalary(string msg) {
		double salary;
		do {
			cout << msg;
			cin >> salary;
		} while (!validateSalary(salary));
		return salary;
	}

	// validate user inputs

	// get double number and get integer number
	static double getDoubleNumber(string msg) {
		double value;
		while (true) {
			cout << msg;
			cin >> value;

			if (cin.fail()) {
				cout << "invalid input please enter valid number!" << endl;

				// clear error flage
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return value;
			}
		}
	}
	static int getIntegerNumber(string msg) {
		int value;
		while (true) {
			cout << msg;
			cin >> value;
			if (cin.fail()) {
				cout << "invalid input please enter valid number!" << endl;

				// clear error flage
				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return value;
			}
		}
	}


};
