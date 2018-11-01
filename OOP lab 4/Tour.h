#pragma once
#include <string>
#include <iostream>
using namespace std;
class Tour{
public:
	string country;
	int lenght;
	int rate;

	Tour(string, int, int, string, string, string, int, int);
	explicit Tour(){};//16 //створення об'єкта тільки через (), явный крнструктор
	~Tour(){
		cout << "Object Tour was destructed" << endl;
	}
	string getHotel();
	string getRoomType();
	string getTransport();
	int getPrice();
	int getDepartureDate();

	void setPrice(int);
private:
	string hotel;
	string room_type;
	string transport;
	int departure_date;
	int price;
};