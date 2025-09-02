#include <iostream>
#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
#include <string>
using namespace std;


class validation
{
    public:
    static bool validname(string name){
       if(name.length()<5||name.length()>20){
    for(int i=0;i<name.length();i++){
        if(!isalpha(name[i]))
           return false;
    }
       }
    return true;
    }
    static bool validpassword(string password){
    if(password.length()<8||password.length()>20)
    {return false;}
    return true;
    }
    static bool validbalance(double balance){
    if(balance <1500){
        return false;
    }
    return true;
    }
    static bool valdisalary(double salary){
    if (salary<5000){
        return false;
    }
    return true;
    }
};

class Person{
    int id;
    string name;
    string password;

public:
    //const
    Person(){
        this->id=0;
    }

    Person(int id,string name,string password){
        set_id(id);
        set_name(name);
        set_password(password);
    }
    //setter
    void set_id(int id){
          this->id=id;
    }
     void set_name(string name){
        if (validation::validname(name))
           this->name=name;
           else cout << "uncorrect name/n";
    }
      void set_password(string password){
       if (validation::validpassword(password))
           this->password=password;
           else cout << "uncorrect password/n";
    }
    //getter
    int get_id(){
        return id;
    }
    string get_name(){
    return name;
    }
     string get_password(){
    return password;
    }

    //methods
    void display(){
        cout <<"id is :" << id<<endl;
        cout <<"name is :" <<name<<endl;
        cout <<"password is :" << password<<endl;
    }
    //dest
     ~Person(){}

};

class Client:public Person{
    double balance;
public:
    //cons
    Client():Person(){
        this -> balance=0;
    }

    Client(int id,string name,string password,double balance):Person(id,name,password){
        set_balance(balance);
    }

      void set_balance(double balance){
        if (validation::validbalance(balance))
           this->balance=balance;
           else cout << "uncorrect balance/n";
      }
    double get_balance(){
    return balance;
    }
    //methods
    void deposit(double amount){
        if (amount >0)
            this->balance+=amount;
    }
    void withdram(double amount){
        if (amount >0&&amount <= balance)
            this->balance-=amount;
    }
    void transefar(double amount, Client&recipient){
        withdram(amount);
         recipient.deposit(amount);
    }
    void check_balance(){
        cout << "balance is "<< balance<<endl;
    }

     void display(){
       Person::display();
        cout <<"balance is :" << balance<<endl;
    }
    //dest
     ~Client(){}
};


class Employee : public Person
{
private:
	double salary;
public:
	Employee() : Person() {
		salary = 0;
	}
	Employee(int id, string name, string password, double salary) : Person(id, name, password) {
		setSalary(salary);
	}

	void setSalary(double salary) {
		if (validation::valdisalary(salary))
			this->salary = salary;
		else cout << "Invalid salary\n";
	}

	double getSalary() {
		return salary;
	}

	void display() {
		Person::display();
		cout << "Salary : " << salary << endl;
	}
};



class Admin : public Employee {
public:
    Admin() : Employee() {}


    Admin(int id, string name, string password, double salary)
        : Employee(id, name, password, salary) {}
};



int main()
{

    return 0;
}
