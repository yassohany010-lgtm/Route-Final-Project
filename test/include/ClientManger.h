#pragma once
#include "FileManager.h"
class ClientManger
{
	static void printClientMenu() {
		system("cls");// clrear screen
		cout << "(1) Display my info" << endl;
		cout << "(2) Check balance" << endl;
		cout << "(3) Update Password" << endl;
		cout << "(4) Withdraw" << endl;
		cout << "(5) Deposit" << endl;
		cout << "(6) Transfer amount" << endl;
		cout << "(7) Logout\n" << endl;
	}
	//static void back(Client* client) {
	//	cout << endl;
	//	system("pause");
	//	clientOptions(client);
	//}

	static void back_exit(Client* client) {
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
				clientOptions(client);
				break;
			default:
				cout << "Invalid!" << endl;
				break;
			}
		} while (c < 0 || c > 1);
	}

public:

	static Client* login(int id, string password) {	 // Authentication // and token

		for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {

			if (cIt->getId() == id && cIt->getPassword() == password) {
				return cIt._Ptr;
			}

		}
		return nullptr;
	}

	static void updatePassword(Person* person) {
		// ask user for new password
		// validate on password
		string newPass;
		do {
			cout << "New password: ";
			cin >> newPass;
		} while (!Validation::validatePass(newPass)); //=>  validation
		// set new password
		person->setPassword(newPass);
		cout << "Password updated" << endl;
	}

	static bool clientOptions(Client* client) {
		printClientMenu();

		int choice;

		double amount;
		int id;
		Client* recipient;
		Employee e;


		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		// after each case
		case 1:
			system("cls");
			client->display();
			break;
		case 2: // check balance
			system("cls");
			client->checkBalance();
			break;
		case 3: // update password
			system("cls");
			updatePassword(client);

			FileManager::updateClients(); // update data in text file => client
			break;
		case 4: // Withdraw
			system("cls");
			// make sure that the user will enter only double number
			amount = Validation::getDoubleNumber("Enter amount: ");
			client->withdraw(amount);
			FileManager::updateClients();
			break;
		case 5: // deposit
			system("cls");
			amount = Validation::getDoubleNumber("Enter amount: "); //
			client->deposit(amount);
			FileManager::updateClients();
			break;
		case 6: //Transfer amount
			system("cls");

			id = Validation::getIntegerNumber("Enter recipient Id: ");

			recipient = e.searchClient(id);

			if (recipient) {
				amount = Validation::getDoubleNumber("Enter amount: ");
				client->transferTo(amount, *recipient);
			}
			else {
				cout << "Account not founded!" << endl;
			}
			break;
		case 7:  // logout
			return false;
			break
;
		default:
			system("cls");
			//cout << "Invalid choice!" << endl;
			clientOptions(client);
			return true;
		}


		back_exit(client);
		return true;
	}
};
