#include<iostream>
#include<algorithm>
using namespace std;
class Employee{
	private:
		static int unique;
		int code;
		string name;
	public:
		Employee():name("default"){
			code = unique++;
		}
		Employee(const string &name){
			this.name = name;
			code = unique++;
		}
		Empoyee(const Empoloyee&)=delete;
		Employee& operator=(const Employee&) = delete;
		const int id() const{ return code;}

};



