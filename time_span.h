
#ifndef TIME_SPAN_H
#define TIME_SPAN_H


#include <iostream>

class TimeSpan {

public:
   //Handles Canonical form
   void normalize();

   //Constructors
   TimeSpan(); //create object, no parameters

   TimeSpan(int seconds); //create object using int, one parameter

   TimeSpan(int minutes, int seconds); //create object using int, two parameters

   TimeSpan(int hours, int minutes, int seconds); //create object using int, three parameters

   //Accessors

   int hours() const; //return number of hours as an int

   int minutes() const; //return number of minutes as an int

   int seconds() const; //return number of seconds as an int

   //mutator
   void set_time(int hours, int minutes, int seconds); //set hours, minutes, seconds

   //Mathematical Operators
   TimeSpan operator+(const TimeSpan& rhs) const; //addition where new object is created
   TimeSpan operator-(const TimeSpan& rhs) const; //subtraction where new object is created
   TimeSpan operator-() const; //unary operator to make everything negative
   //return a new object, and not modify the og object

   TimeSpan& operator+=(const TimeSpan& rhs); //+= operator adjust object but not rhs
   TimeSpan& operator-=(const TimeSpan& rhs); //-= operator. adjust object but not rhs


   //Comparison Operators
   bool operator==(const TimeSpan& rhs) const; //check if two time spans are equal, do not change objects
   bool operator!=(const TimeSpan& rhs) const; //check if two timeSpans are not equal, do not change objects
   bool operator<(const TimeSpan& rhs) const; //check if a<b, do not change objects
   bool operator<=(const TimeSpan& rhs) const; // check if a<=b, but do not change objects
   bool operator>(const TimeSpan& rhs) const; //check if a>b, do not change objects
   bool operator>=(const TimeSpan& rhs) const; //check if a>=b, do not change objects

   //Stream I/O Operators
   friend std::ostream& operator<<(std::ostream& out, const TimeSpan& ts);//friend = access to private fields
   //standard output stream, with parameters on inside, const is bc we want to ensure ts is not changed
   friend std::istream& operator>>(std::istream& in, TimeSpan& ts); //no const because we must ensure it will change
   //as it reads input, and we use & because this is a reference for the .cpp file to always use

private:
   int hours_;
   int minutes_;
   int seconds_;

};

#endif// TIME_SPAN_H
//end of that check

