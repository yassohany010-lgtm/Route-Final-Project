#pragma once
#include"Admin.h"
class DataSourceInterface
{
protected:
	virtual void addClient(Client obj) = 0;
	virtual void addEmployee(Employee obj) = 0;
	virtual void addAdmin(Admin obj) = 0;

	virtual void getAllClients() = 0;
	virtual void getAllEmployees() = 0;
	virtual void getAllAdmins() = 0;

	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;
};
