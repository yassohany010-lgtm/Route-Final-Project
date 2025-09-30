#pragma once
#include"Admin.h"
#include<sstream>
class Parser
{
private:
	static vector<string> split(string line) {
		// id/name/pass/balance
		vector<string> info;
		stringstream stream(line);
		string token;
		while (getline(stream, token, '/')) {
			info.push_back(token);
		}
		return info;
	}
public:

	static Client parseToClient(string line) {
		// 0    1    2     3
		// id/name/pass/balance
		Client clinet; // => id , name , pass , balance

		vector<string> clientInfo;

		clientInfo = split(line);
		// 0     1       2       3
		// id | name | pass |  balance

		clinet.setId( stoi(clientInfo[0])  );

		clinet.setName(clientInfo[1]);

		clinet.setPassword( clientInfo[2] );

		clinet.setBalance(stod(clientInfo[3]) );

		return clinet;
	}

	static Employee parseToEmployee(string line) {
		// 0    1    2     3
		// id/name/pass/balance
		Employee emp;

		vector<string> empInfo;

		empInfo = split(line);

		// 0    1    2     3
		// id | name |pass |balance
		emp.setId(stoi(empInfo[0]));
		emp.setName(empInfo[1]);
		emp.setPassword(empInfo[2]);
		emp.setSalary(stod(empInfo[3]));
		return emp;
	}

	static Admin parseToAdmin(string line) {
		// 0    1    2     3
		// id/name/pass/balance
		Admin admin;
		vector<string> adminInfo;
		adminInfo = split(line);
		admin.setId(stoi(adminInfo[0]));
		admin.setName(adminInfo[1]);
		admin.setPassword(adminInfo[2]);
		admin.setSalary(stod(adminInfo[3]));
		return admin;
	}
};
