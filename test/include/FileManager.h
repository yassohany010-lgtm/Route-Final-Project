#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
class FileManager : public DataSourceInterface
{
public:
	static void addClient(Client obj) {
		FilesHelper::saveClient(obj);
	}

	static void addEmployee(Employee obj) {
		FilesHelper::saveEmployee(obj);
	}

	static void addAdmin(Admin obj) {
		FilesHelper::saveAdmin(obj);
	}

	static void getAllClients() {
		FilesHelper::getAllClients();
	}

	static void getAllEmployees() {
		FilesHelper::getAllEmployees();
	}

	static void getAllAdmins() {
		FilesHelper::getAllAdmins();
	}

	static void removeAllClients() {
		FilesHelper::clearFile(C_FILE_PATH, CID_FILE_PATH);
	}

	static void removeAllEmployees() {
		FilesHelper::clearFile(E_FILE_PATH, EID_FILE_PATH);
	}

	static void removeAllAdmins() {
		FilesHelper::clearFile(A_FILE_PATH, EID_FILE_PATH);
	}


	static void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}

	static void updateClients() {
		removeAllClients();

		for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {
			addClient(*cIt);
		}
	}

	static void updateEmployees() {
		removeAllEmployees();
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			addEmployee(*eIt);
		}
	}
	static void updateAdmins() {
		removeAllAdmins();
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) {
			addAdmin(*aIt);
		}
	}

};
