//
// Created by Bruno Futino on 10/17/2021.
//

#include "timespan.h"
#include <math.h>
#include <iomanip>
  // overloaded << operator
  // determines how ostream will behave with the object
  // out is being formatted to include a 0 for minutes and seconds < 10
  // if timespan is negative, then a negative sign is going to be added to the message
  // otherwise will be printed normally
ostream &operator<<(ostream &out, const TimeSpan &ts) { 
  if(!ts.isPositive()){
    out << "-" << abs(ts.getHour()) << ':' << setw(2) << setfill('0') << abs(ts.getMinute()) << ':' 
  << setw(2) << setfill('0') << abs(ts.getSecond());
  }else{
     out << ts.getHour() << ':' << setw(2) << setfill('0') << ts.getMinute() << ':' 
  << setw(2) << setfill('0') << ts.getSecond();
  }

  return out; 
  }

// explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
// default constructor with default value of 0
// calls convert function to ensure that minutes and seconds are less than 60
TimeSpan::TimeSpan(double hour, double minute, double second) : hour(hour), minute(minute), second(second) {
  convert();
}

// hour component
//returns hour 
int TimeSpan::getHour() const { return hour; }

// minute component
//returns minute
int TimeSpan::getMinute() const { return minute; }

// second component
//returns second
int TimeSpan::getSecond() const { return second; }

//check if time is positive
// returns true if timespan is 0 or larger, otherwise returns false
bool TimeSpan::isPositive() const { 
  int totalSec = (hour * 3600) + (minute * 60) + second;
  
  if(totalSec >= 0){
    return true;
  }
  return false;
   }

// Overloaded addition operator
// every time variable (hour, minute, second) is added by ts object into new object
// new object is converted to standard format where minutes and seconds are less than 60
// new object is return with values of this + ts
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
  TimeSpan tsSum;
  tsSum.hour = this->hour + ts.hour;
  tsSum.minute = this->minute + ts.minute;
  tsSum.second = this->second + ts.second;
  tsSum.convert();
  return tsSum;
}

// Overloaded subtraction operator
// every time variable (hour, minute, second) is subtracted by ts object into new object
// new object is converted to standard format hh:mm:ss where ss and mm < 60
// new object is return with values of this - ts
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
  TimeSpan tsSub;
  tsSub.hour = this->hour - ts.hour;
  tsSub.minute = this-> minute - ts.minute;
  tsSub.second = this->second - ts.second; 
  tsSub.convert();
  return tsSub;
}

// multiply this object with an integer
// every time variable (hour, minute, second) is multiplied by number given
// convert function is called to format object so minutes and seconds are less than 60
// new object is returned after being multiplied and formatted
TimeSpan TimeSpan::operator*(unsigned int number) const {
  TimeSpan tsLarge;

  tsLarge.hour = this->hour * number;
  tsLarge.minute = this->minute * number;
  tsLarge.second = this->second * number;
  tsLarge.convert();
  return tsLarge;
}

// Overloaded equality == operator
// Defines how equality operator is going to be used
// Compares every time variable(hour, minute, second) and if they all match returns true
// otherwise returns false
// Both objects are in standard format so they can be compared
bool TimeSpan::operator==(const TimeSpan &ts) const {
  return (hour == ts.hour) && (minute == ts.minute) && (second == ts.second); 
  }

// Overloaded inequality != operator
// Defined how inequality is going to be calculated
// Compares against already defined equality function
// if this object is different than ts it returns true, otherwise returns false
bool TimeSpan::operator!=(const TimeSpan &ts) const { 
  return !(*this == ts); 
  }

// Overloaded += operator
// Defines how += is going to be used
// increments t to this object
// calls convert function to convert it to standard format after incrementing
// returns object after incrementing
TimeSpan& TimeSpan::operator+=(const TimeSpan &t){
  hour += t.hour;
  minute += t.minute;
  second += t.second;
  convert();
  return *this;
}

// Overloaded -= operator
// Defines how -= is going to be used
// decrements t from this object
// calls convert function to convert it to standard format after decrementing
// returns object after decrementing
TimeSpan& TimeSpan::operator-=(const TimeSpan &t){
  hour -= t.hour;
  minute -= t.minute;
  second -= t.second;
  convert();
  return *this;
}

// Overloaded < operator
// defines how < is going to be used
// function converts both this object and input object to seconds and check which one is greater
// if this object is less than t returns true, otherwise returns false
bool TimeSpan::operator<(const TimeSpan &t)const{
  int t1 = (hour*3600) + (minute * 60) + second;
  int t2 = (t.hour*3600) + (t.minute * 60) + t.second;

  return t1 < t2;
}

// Overloaded > operator
//Compares against existent < function
// returns true if this is greater than t, otherwise returns false
bool TimeSpan::operator>(const TimeSpan &t)const{
  return !(*this < t);
}

// Overloaded <= operator
// compares this to existent function == and < 
// returns true if this is greater or equals to t, otherwise returns false
bool TimeSpan::operator<=(const TimeSpan &t)const{
  return (*this == t) || (*this < t);
}

// Overloaded >= operator
// compares to the already established < function
// returns true if this is less or equals to t, otherwise returns false
bool TimeSpan::operator>=(const TimeSpan &t)const{
  return !(*this < t);
}

//Convert function
//Converts total time to seconds and then back to the standard format hh:mm:ss where m and s are less than 60
void TimeSpan::convert(){
  int temp = (hour * 3600) + (minute * 60) + second;

  hour = ceil(temp/3600);
  temp -= hour * 3600;
  minute = ceil(temp/60);
  temp -= minute * 60;
  second = temp;
}
