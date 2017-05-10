#pragma once

#include <iostream>
#include <vector>

class Driver;


using namespace std;

class Shift{
 private:
  unsigned int busLineId;
  unsigned int driverId;
  unsigned int busOrderNumber;
  unsigned int startTime;
  unsigned int endTime;

 public:
  Shift(unsigned int busLineId, unsigned int driverId, unsigned int busNumber, unsigned int startTime, unsigned int endTime);
  // get methods
  unsigned int getBusLineId() const;
  unsigned int getDriverId() const;
  unsigned int getBusOrderNumber() const; // order of the bus within the bus line
  unsigned int getStartTime() const;
  unsigned int getEndTime() const;

  //  set methods
  unsigned int setBusLineId(unsigned int);
  unsigned int setDriverId(unsigned int);
  unsigned int setBusOrderNumber(unsigned int);
  unsigned int setStartTime(unsigned int);
  unsigned int setEndTime(unsigned int);

  // other methods
  friend ostream& operator<<(ostream &os, const Shift shift);
};
