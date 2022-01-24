//
// Created by Bruno Futino on 10/17/2021.
//

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>

using namespace std;

class TimeSpan {
  //overloaded << 
  //determines how ostream will behave with the object
  friend ostream &operator<<(ostream &out, const TimeSpan &ts);

public:
  // explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
  //Constructor with default values
  explicit TimeSpan(double hour = 0, double minute = 0, double second = 0);



  //---------------------- Operator Overloading ----------------------

  // overloaded + operator
  // addition of 2 TimeSpan objects
  TimeSpan operator+(const TimeSpan &ts) const;

  // overloaded - operator
  // subtraction of 2 TimeSpan objects
  TimeSpan operator-(const TimeSpan &ts) const;

  // overloaded == operator
  // check equality of 2 timeSpan objects
  bool operator==(const TimeSpan &ts) const;

  // overloaded != operator
  // check if not equal
  bool operator!=(const TimeSpan &ts) const;

  // overloaded * operator
  // multiply timespan by an unsigned number
  TimeSpan operator*(unsigned int number) const;

  // overloaded += operator
  // allows to increment object by t
  TimeSpan &operator+=(const TimeSpan &t);

  // overloaded -= operator
  // allows to decrement from object by t
  TimeSpan &operator-=(const TimeSpan &t);

  // overloaded < operator
  // checks if object is < than parameter
  bool operator<(const TimeSpan &t) const;

  // overloaded > operator
  // checks if object is > than parameter
  bool operator>(const TimeSpan &t)const;

  // overloaded <= operator
  // checks if object is <= parameter
  bool operator<=(const TimeSpan &t)const;

  // overloaded >= operator
  // checks if object is >= parameter
  bool operator>=(const TimeSpan &t)const;



  //---------------------- Methods ----------------------

  // hour component of timespan
  int getHour() const;

  // minute component of timespan
  int getMinute() const;

  // second component of timespan
  int getSecond() const;

  // true if timespan is 0 or larger
  bool isPositive() const;


private:
  double hour, minute, second;
  //converts time to match standard format hh:mm:ss
  void convert();
};

#endif // ASS2_TIMESPAN_H
