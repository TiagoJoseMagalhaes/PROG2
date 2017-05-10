#include "Driver.h"
#include <iostream>

Driver::Driver(string name, unsigned int id, unsigned int maxHours, unsigned int maxWeekWorkingTime, unsigned int minRestTime){
	this->id = id;
	this->maxHours = maxHours;
	this->maxWeekWorkingTime = maxWeekWorkingTime;
	this->minRestTime = minRestTime;
	this->name = name;
}

//////////////
// get methods
//////////////

unsigned int Driver::getId() const{
  return id;
}

string Driver::getName() const{
  return this->name;
}

unsigned int Driver::getShiftMaxDuration() const{
  return maxHours;
}

unsigned int Driver::getMaxWeekWorkingTime() const{
  return maxWeekWorkingTime;
}

unsigned int Driver::getMinRestTime() const{
  return minRestTime;
}

vector<Shift> Driver::getShifts() const{
  return shifts;
}

void Driver::setName(std::string name)
{
	this->name = name;
}

void Driver::setMaxHoursPerShift(unsigned int time)
{
	this->maxHours = time;
}

void Driver::setMaxHoursPerWeek(unsigned int time)
{
	this->maxWeekWorkingTime = time;
}

void Driver::setRestTimeBetweenShifts(unsigned int time)
{
	this->minRestTime = time;
}

void Driver::assignShift(Shift shift)
{
	unsigned int delta = 0;
	delta = shift.getEndTime() - shift.getStartTime();
	if (delta > this->maxHours) {
		printf("This Shift Is Too Long For this Driver\n");
		return;
	}
	if (currentWeekTime + delta > this->maxWeekWorkingTime) {
		printf("With This Shift the Driver Would Go over the Max Hours per Week He Can Work For\n");
		return;
	}
	for (std::vector<Shift>::iterator it = this->shifts.begin();it != this->shifts.end();++it) {
		if ((it->getEndTime() - shift.getStartTime()) < this->minRestTime) {
			printf("This Shift Doesnt Allow The Driver To Rest Properly Between Shift\n");
			return;
		}
	}
	this->currentWeekTime += delta;
	this->shifts.push_back(shift);
}

void Driver::listWork()const {
	std::cout << "Driver ID:" << this->getId() << std::endl;
	std::cout << "\tWork:" << std::endl;
	for (std::vector<Shift>::const_iterator it = this->shifts.begin();it != this->shifts.end();++it) {
		std::cout << "\t" << *it << std::endl;
	}
	return;
}
