#pragma once
#include <iostream>
#include <string>
#include "Tour.h"
#include "Man.h"

using namespace std;
class Admin;
class TouristData;
class Tourist:public Man{
public:
	int our_client_since;
	Tourist(string, string , string, string, int, int, int, int, int, int);
	Tourist(string name, string surname, int age) :Man(name, surname, age){};
	Tourist();
	~Tourist(){
		cout << "Object Tourist was destructed" << endl;
	}
	void ChooseTour(Tour *, string, int, Admin);
	void PayForTour(int);
	void PayForTour();
	void PlaceOrder();
	void MakeOrder(Tour);
	//void MakeOrder(Tour, string);
	int GetOrdersPrice();
	int GetOrdersPrice(int);
	void ChooseTourForMoney(Tour *, int, int, Admin);

	int getCardNumber();
	
	int getId();
	int getInsurance();
	int getMoney();

	void RandMemory();
	string ClassName();

	void setCardNumber(int);

	friend TouristData;//11 дружній клас

private:
	int id;
	int card_number;
	int insurance;
	int money;
};

class TouristData{//11
public:
	string insurance_company;
	void setStatus(Tourist &ob){
		if (ob.getInsurance() % 2 == 0){
			insurance_company = "Bakkt company";
		}
		else{
			insurance_company = "Plaza company";
		}
	}

};