

#pragma once
#include "Employee.h"
class Admin : public Employee
{
public:
	Admin() {

	}
	//
	Admin(int id, string name, string pass, double balance) :
		Employee(id, name, pass, balance) {

	}

	void AddEmploye(Employee& emp) {
		allEmployees.push_back(emp);
	}

	Employee* searchEmployee(int id) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() == id) return eIt._Ptr;
		}
		return nullptr;
	}

	void editEmployee(Employee* emp, string name, string password, double salary) {
		emp->setName(name);
		emp->setPassword(password);
		emp->setSalary(salary);
	}

	void listEmployee() {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			eIt->display();
		}
	}

};

static vector<Admin> allAdmins;
static vector<Admin>::iterator aIt;
