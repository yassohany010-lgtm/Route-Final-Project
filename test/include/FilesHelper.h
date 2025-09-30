
#pragma once
#include<fstream>
#include"parser.h"

#define C_FILE_PATH "data/clients.txt"
#define E_FILE_PATH "data/employees.txt"
#define A_FILE_PATH "data/admins.txt"

/// file for id
#define CID_FILE_PATH "data/clients_id.txt"
#define EID_FILE_PATH "data/employees_id.txt"
#define AID_FILE_PATH "data/admins_id.txt"

class FilesHelper
{
private:
	static void savLastId(string fileName, int id) {
		fstream file;
		file.open(fileName, ios::out);
		file << id;
		file.close();
	}
public:

	static int getLastId(string fileName) {
		fstream file;
		file.open(fileName, ios::in);
		int id;
		file >> id;
		file.close();
		return id;
	}

	static void saveClient(Client c) {
		// id/name/pass/balance
		//int id = getLastId(CID_FILE_PATH);
		fstream file;
		file.open(C_FILE_PATH, ios::app);
		file << c.getId() << '/' << c.getName() << '/' << c.getPassword() << '/' << c.getBalance() << endl;
		file.close();
		//int lastId = c.getId();
		savLastId(CID_FILE_PATH, c.getId());
	}

	static void saveEmployee(Employee emp) {
		fstream file;
		//int id = getLastId(EID_FILE_PATH);
		file.open(E_FILE_PATH, ios::app);
		file << emp.getId() << '/' << emp.getName()<< '/' << emp.getPassword() << '/' << emp.getSalary() << endl;
		file.close();
		savLastId(EID_FILE_PATH, emp.getId());
	}

	static void saveAdmin(Admin admin) {
		fstream file;
		//int id = getLastId(AID_FILE_PATH);
		file.open(A_FILE_PATH, ios::app);
		file << admin.getId() << '/' << admin.getName() << '/' << admin.getPassword() << '/' << admin.getSalary() << endl;
		file.close();
		savLastId(AID_FILE_PATH, admin.getId());
	}

	static void getAllClients() {
		fstream file;
		file.open( C_FILE_PATH, ios::in);
		string line;
		while (getline(file, line)) {
			allClients.push_back(Parser::parseToClient(line));
		}
	}

	static void getAllEmployees() {
		fstream empFile;
		empFile.open(E_FILE_PATH, ios::in);
		string line;
		while (getline(empFile, line)) {
			allEmployees.push_back(Parser::parseToEmployee(line));
		}
	}
	static void getAllAdmins() {
		fstream adminFile;
		adminFile.open(A_FILE_PATH, ios::in);
		string line;
		while (getline(adminFile, line)) {
			allAdmins.push_back(Parser::parseToAdmin(line));
		}
	}
	// if you want to clear Clients File you have to clear Client Id file
	static void clearFile(string fileName, string LastIdFile) {
		fstream file;
		file.open(fileName, ios::out);
		file.close();
		file.open(LastIdFile, ios::out);
		file << 0;
		file.close();
	}
};
