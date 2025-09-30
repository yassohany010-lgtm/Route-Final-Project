#pragma once
#include "ClientManger.h"
class EmployeeManager
{

	static void printEmployeeMenu() {
		system("cls");
		cout << "(1) Display my info" << endl;
		cout << "(2) Update Password" << endl;
		cout << "(3) Add new client" << endl;
		cout << "(4) Search for client" << endl;
		cout << "(5) List all clients" << endl;
		cout << "(6) Edit client info" << endl;
		cout << "(7) Logout\n" << endl;
	}

	//static void back(Employee* employee) {
	//	cout << endl;
	//	system("pause");
	//	employeeOptions(employee);
	//}

	static void back_exit(Employee* employee) {
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
				employeeOptions(employee);
				break;
			default:
				cout << "Invalid!" << endl;
				break;
			}
		} while (c < 0 || c > 1);
	}

public:

	static void newClient(Employee* employee) {
		Client client;
		//0- generate unique id
		int id = FilesHelper::getLastId(CID_FILE_PATH) + 1;

		//1- ask user for Client data  => name, password, balance
		//input this data  => name , password, balance
		//validate on this data
		client.setId(id);
		client.setName(   Validation::enterName("Client name: ")  );
		client.setPassword(Validation::enterPassword("Client password: "));
		client.setBalance(Validation::enterBalance("Client balance: "));

		// use employee to add new Clinet to vector Clinets,
		employee->addClient(client);
											//FileManager::updateClients();
		FileManager::addClient(client); // will save clinet to txt file and last id used
		cout << "Client added successfully";
	}



	static void listAllClient(Employee* employee) {
		//system("cls");
		cout << "All Clients: \n" << endl;
		employee->listClient();
	}
	static void searchForClient(Employee* employee) {

		int id;
		//system("cls");
		id = Validation::getIntegerNumber("Enter clinet id: ");

		Client* client = employee->searchClient(id);

		// client => nulptr , client
		if (client == nullptr) cout << "Client Not Founded" << endl;
		else client->display();
	}
	static void editClientInfo(Employee* employee) {


		int id = Validation::getIntegerNumber("Enter client id: ");


		Client* client =  employee->searchClient(id); // nullptr / client



		if (client != nullptr) {
			cout << "===== Update data =====" << endl;


			string name = Validation::enterName("Client name: ");
			string pass = Validation::enterPassword("Client password: ");
			double balance = Validation::enterBalance("Client balance: ");


			employee->editClient(client, name, pass, balance);

			// update text file
			FileManager::updateClients();

			cout << "Client data updated successfully" << endl;
		}
		else {
			cout << "Client not found" << endl;
		}
	}


	static Employee* login(int id, string pass) {

		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() == id && eIt->getPassword() == pass) return eIt._Ptr;
		}
		return nullptr;

	}

	static bool employeeOptions(Employee* employee) { // authrization =>
		printEmployeeMenu();
		int choice;
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		case 1:// Display my info
			system("cls");
			employee->display();
			break;
		case 2: //Update Password
			system("cls");
			ClientManger::updatePassword(employee);
			FileManager::updateEmployees();
			break;
		case 3:  //Add new client // crud => create , read, update, delete
			system("cls");
			newClient(employee);
			break;
		case 4: // Search for client
			system("cls");
			searchForClient(employee);
			break;
		case 5: //List all clients
			system("cls");
			listAllClient(employee);
			break;
		case 6: //Edit client info
			system("cls");
			editClientInfo(employee);
			break;
		case 7: // logout
			return false;
			break;
		default:
			system("cls");
			//cout << "Invalid choice!" << endl;
			employeeOptions(employee);
			return true;
		}

		back_exit(employee);
		return true;
	}
};
