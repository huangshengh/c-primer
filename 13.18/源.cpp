#include <string>

using std::string;

class Employee
{
	Employee();
	Employee(string s) :name(s) {  number += 1; }
	string name;
	static int number;

};