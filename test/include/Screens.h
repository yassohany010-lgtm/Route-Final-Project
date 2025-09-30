#pragma once
#include"AdminManager.h"
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <windows.h>
class Screens
{
	static void bankName() {
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t    ## #                 ##  ##         ## #" << endl;
		cout << "\t\t\t\t    ## #####    #####    ##  ##      ## ##   ##   ##" << endl;
		cout << "\t\t\t\t    ####   ##       ##   ##  ##  ## ##  ##   ##   ##" << endl;
		cout << "\t\t\t\t  #########################  ##  ###################" << endl;
		cout << "\t\t\t\t                                                #" << endl;
		Sleep(2000);
	}

	static void welcome() {
		system("Color 3f");

		bankName();
		//Sleep(2000);
		system("cls");


		int t = 150;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t     ##" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t     ##" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t     ##         ###           #####" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t     ##   ##      ##   ##    ##   ##" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t     ###############   #############" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t           #           ##" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t                      ##" << endl;
		Sleep(t);
		cout << "\t\t\t\t\t                    ##" << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n";
		Sleep(1000);
		system("cls");
		system("Color 0f");
	}


	static void loginOptions() {
		cout << "(1) Admin" << endl;
		cout << "(2) Employee" << endl;
		cout << "(3) Client\n" << endl;
		//cout << "Login as: ";
	}


	static int loginAs() {

		loginOptions();


		int choice = Validation::getIntegerNumber("Login as: ");


		if (choice == 1 || choice == 2 || choice == 3) {
			system("cls");
			return choice;
		}
		else {
			system("cls");
			return loginAs();
		}
	}


	static void invalid(int c) {
		system("cls");
		cout << "Incorrect id or password!\n" << endl;
		loginScreen(c);
	}


	static void logout() {
		system("cls");
		loginScreen(loginAs());
	}

public:

	static void loginScreen(int c) {
		int choice = c, id;
		string pass;


		id = Validation::getIntegerNumber("Enter ID: ");

		cout << "Enter password: ";
		cin >> pass;


		switch (choice)
		{
		case 1:// admin

			//Admin* admin = AdminManager::login(id, pass);
			if (AdminManager::login(id, pass) != nullptr) {
				while (AdminManager::adminOptions(AdminManager::login(id, pass)) != false);
				logout();
			}
			else invalid(1);
			break;


		case 2: // employee
			if (EmployeeManager::login(id, pass) != nullptr) {
				while (EmployeeManager::employeeOptions(EmployeeManager::login(id, pass)) != false);
				logout();
			}
			else invalid(2);
			break;


		case 3: // client
			if (ClientManger::login(id, pass) != nullptr)
			{
				while (ClientManger::clientOptions(ClientManger::login(id, pass)) != false);
				logout();
			}
			else invalid(3);
			break;
		default:
			system("cls");
			loginOptions(); ///
		}
	}

	static void runApp() {
		FileManager::getAllData();


		welcome();


		loginScreen(loginAs());
	}

};
