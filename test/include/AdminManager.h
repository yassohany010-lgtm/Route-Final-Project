#pragma once
#include"EmployeeManager.h"
class AdminManager
{
private:
	static void printAdminMenu() {
		system("cls");
		cout << "(1) Display my info" << endl;
		cout << "(2) Update Password" << endl;
		cout << "(3) Add new client" << endl;
		cout << "(4) Search for client" << endl;
		cout << "(5) List all clients" << endl;
		cout << "(6) Edit client info" << endl;
		cout << "(7) Add new Employee" << endl;
		cout << "(8) Search for Employee" << endl;
		cout << "(9) List all Employees" << endl;
		cout << "(10) Edit Employee info" << endl;
		cout << "(11) Logout\n" << endl;
	}
	//static void back(Admin* admin) {
	//	cout << endl;
	//	system("pause");
	//	adminOptions(admin);
	//}
	static void back_exit(Admin* admin) {
		int c;
		do {
			cout << "\n\n(1) Options\t\t(0) Exit\n";
			c = Validation::getIntegerNumber("..::Enter Choice: ");
			switch (c)
			{
			case 0:
				exit(0);
				break;
			case 1:
				system("cls");
				adminOptions(admin);
				break;
			default:
				cout << "Invalid!" << endl;
				break;
			}
		} while (c < 0 || c > 1);
	}

public:
	static Admin* login(int id, string password) {
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) {
			if (aIt->getId() == id && aIt->getPassword() == password)return aIt._Ptr;
		}
		return nullptr;
	}

	static void newEmployee(Admin* admin) {
		Employee emp;
		//0- generate unique id          // 0 => 1
		int id = FilesHelper::getLastId(EID_FILE_PATH) + 1;
		//1- ask user for Employee data  => name, password, salary
		//validate on this data
		//set data  => name , password, salary
		emp.setId(id);

		emp.setName(Validation::enterName("Employee name: "));
		emp.setPassword(Validation::enterPassword("Employee password: "));
		emp.setSalary(Validation::enterSalary("Employee salary: "));


		// use admin to add new Clinet, to the vector
		admin->AddEmploye(emp);

		// add this client to text file
		FileManager::addEmployee(emp);


		cout << "Employee added successfully" << endl;
	}

	static void serrchForEmployee(Admin* admin) {
		int id = Validation::getIntegerNumber("Enter Employee id: ");

		//admin->searchClient()

		Employee* emp = admin->searchEmployee(id);
		if (emp != nullptr) emp->display();
		else cout << "Employee not founded!" << endl;
	}

	static void listAllEmployee(Admin* admin) {
		cout << "All Employee:" << endl;
		admin->listEmployee();
	}

	static void editEmployeeInfo(Admin* admin) {

		int id = Validation::getIntegerNumber("Enter employee id: ");


		Employee* emp = admin->searchEmployee(id);

		if (emp != nullptr) {

			string name = Validation::enterName("Employee name: ");
			string pass = Validation::enterPassword("Employee password: ");
			double salary = Validation::enterSalary("Employee salary: ");


			admin->editEmployee(emp, name, pass, salary);


			//update text file
			FileManager::updateEmployees();

			cout << "Employee data updated successfuly" << endl;
		}
		else {
			cout << "Employee not founded" << endl;
		}
	}

	static bool adminOptions(Admin* admin) {
		printAdminMenu();
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: // Display my info
			system("cls");
			admin->display();
			break;
		case 2: //Update Password
			system("cls");
			ClientManger::updatePassword(admin);

			FileManager::updateAdmins();
			break;
		case 3:  // Add new client
			system("cls");
			EmployeeManager::newClient(admin);
			break;
		case 4: // Search for client
			system("cls");
			EmployeeManager::searchForClient(admin);
			break;
		case 5: // List all clients
			system("cls");
			EmployeeManager::listAllClient(admin);
			break;
		case 6: // Edit client info
			system("cls");
			EmployeeManager::editClientInfo(admin);
			break;
		case 7:  // add new employe
			system("cls");
			newEmployee(admin);
			break;
		case 8: // search for employee
			system("cls");
			serrchForEmployee(admin);
			break;
		case 9:  // list All Employee
			system("cls");
			listAllEmployee(admin);
			break;
		case 10: // Edit Employee info
			system("cls");
			editEmployeeInfo(admin);
			break;
		case 11:  // Logout
			return false;
			break;
		default:
			system("cls");
			//cout << "Invalid choice!" << endl;
			adminOptions(admin);
			return true;
		}
		back_exit(admin);
		return true;
	}

};
