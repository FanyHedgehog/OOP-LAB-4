#pragma once
#include <string>
#include "Man.h"
#include "Tourist.h"

class Critic : public Tour, protected Man{//10
private:
	int mark;
public:
	Critic(Tour tour, Man man, int mark) :Tour(tour.country, tour.lenght, tour.rate, tour.getHotel(), tour.getRoomType(), tour.getTransport(), tour.getPrice(), tour.getDepartureDate()), Man (man.name, man.surname, man.getAge()){
	}
	Critic(){};
	void setMark(Tour tour, int mark){
		cout << "Mark of tour to " << tour.country << " is " << mark << endl;
	}
};