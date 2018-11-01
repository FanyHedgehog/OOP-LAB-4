#include <iostream>
#include <string>
#include "Tour.h"
#include "Tourist.h"
#include "Admin.h"
#include "Man.h"
#include "CEO.h"
#include "Agency.h"


using namespace std;


void StartWorkAge(Admin admin);//19 перевантаженння
void StartWorkAge(Admin* &admin);//20

int Admin::salary;
void main(){
	Admin *admin = new Admin("Petro", "Petrov", "B", 25, "man", "manager", "High", 4, 1000);
	StartWorkAge(admin);//19-20
	admin->AddTour("Ukraine", 10, 4, "HUkraine", "a", "bus", 11, 200);
	admin->AddTour("France", 11, 5, "HFrance", "b", "plane", 15, 1000);
	cout << "Hello! The rules of the program. If you want to say yes, press 1, if no - press 0" << endl;
	Tourist *tourist = new Tourist("Ivan", "Ivanov", "C", "man", 25, 2010, 65442, 63592565, 63474, 10000);//статична пам'ять

	admin->setTourist(tourist);
	cout << "Enter price?" << endl;
	Tour *tour_mass = new Tour[4];//це не працює без Tour(){},динамічна пам'ять,масив об'
	Agency agency(admin, tourist, tour_mass, "Around the world", "Email", 123456, "Owner", 2, 2, 1, 2);
	admin->ReadTourFromFile(tour_mass, 4);
	int count_orders = 0;
	string country_tour;
	int price;
	cin >> price;
	count_orders++;
	tourist->ChooseTourForMoney(tour_mass, price, 4, *admin);
	bool yes_no = 0;
	cout << "Do you need other or one more tour?" << endl;
	cin >> yes_no;
	if (yes_no == 1){
		cout << "Enter country:" << endl;
		cin >> country_tour;
	}
	if (yes_no == 1){
		count_orders++;
		tourist->ChooseTour(tour_mass, country_tour, 2, *admin);
	}
	cout << "Do you want pay for order(s)" << endl;
	cin >> yes_no;

	if (yes_no == 1){
		cout << "Last price your orders is " << tourist->GetOrdersPrice(count_orders) << ". Do you want pay by card: " << tourist->getCardNumber() << " ?" << endl;
	}
	cin >> yes_no;
	if (yes_no == 1){
		tourist->PayForTour(tourist->GetOrdersPrice(count_orders));
	}
	else{

		cout << "Please, enter new cardnumber" << endl;
		int cardnumber;
		cin >> cardnumber;
		tourist->setCardNumber(cardnumber);
		if (tourist->getCardNumber() % 2 == 0){
			tourist->PayForTour();
		}
		else{
			tourist->PayForTour(tourist->GetOrdersPrice(count_orders));
		}

	}
	cin.get();
	cin.get();
}

void StartWorkAge(Admin admin){//19
	cout << "Admin started carreer at " << admin.getAge() - admin.getWorkExperience() << endl;
}
void StartWorkAge(Admin* &admin){//20
	cout << "Admin started carreer at " << admin->getAge()/* - admin->getWorkExperience() */<< endl;
}