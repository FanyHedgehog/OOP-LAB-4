#pragma once
#include "string"
using namespace std;
class Man{
public:
	string name;
	string surname;
	Man(string, string, string, string, int);
	Man(string, string, int);
	Man(){};
	int getAge();
protected:
	string english_level;
	int age;
	string sex;
private:
	
};