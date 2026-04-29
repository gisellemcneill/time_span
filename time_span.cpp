// ------------------------------------------------ TimeSpan.cpp ------------------------------------------------------

// Giselle McNeill
// CSS343

// Creation Date: 1/23/26
// Last Modified: 4/29/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// This file implements the TimeSpan class, which represents a duration of time
// using hours, minutes, and seconds. It supports normalization, arithmetic
// operations, comparisons, and stream input/output via operator overloading.
//
// The class ensures all TimeSpan objects are stored in canonical form using
// the normalize() function, which handles overflow between seconds, minutes,
// and hours.
//
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "time_span.h"
using namespace std;

// --------------------------------------------------------------------------------------------------------------------
// normalize()
// Ensures the TimeSpan is in canonical form by adjusting seconds, minutes,
// and hours so that:
// - seconds and minutes stay within [-59, 59]
// - overflow is carried into the next unit
// --------------------------------------------------------------------------------------------------------------------

void TimeSpan::normalize() {
    //add extra minutes and assign the leftover seconds
    if (seconds_ >= 60 || seconds_ <= -60) {
        minutes_ += seconds_ / 60;
        seconds_ %= 60;
    }

    //borrow from minutes to adjust seconds
    if (seconds_ < 0 && minutes_ > 0) {
        seconds_ += 60;
        minutes_ -= 1;
        //adjust seconds to match minutes so both are negative
    } else if (seconds_ > 0 && minutes_ < 0) {
        seconds_ -= 60;
        minutes_ += 1;
    }

    //add to hours to balance minutes
    if (minutes_ >= 60 || minutes_ <= -60) {
        hours_ += minutes_ / 60;
        minutes_ %= 60;
    }

    //if minutes are negative, borrow from hours to balance
    if (minutes_ < 0 && hours_ > 0) {
        minutes_ += 60;
        hours_ -= 1;
        //if hours are negative, borrow from minutes to make both negative
    } else if (minutes_ > 0 && hours_ < 0) {
        minutes_ -= 60;
        hours_ += 1;
    }
}

// --------------------------------------------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------------------------------------------

   TimeSpan::TimeSpan() {
        hours_ = 0;
        minutes_ = 0;
        seconds_ = 0;
    }

    TimeSpan::TimeSpan(int s) {
        seconds_ = s;
        minutes_ = 0;
        hours_ = 0;
       normalize();
    }

    TimeSpan:: TimeSpan(int m, int s) {
        seconds_ = s;
        minutes_ = m;
        hours_ = 0;
       normalize();
    }

    TimeSpan::TimeSpan(int h, int m, int s) {
        seconds_ = s;
        minutes_ = m;
        hours_ = h;
        normalize();
    }

// --------------------------------------------------------------------------------------------------------------------
// Accessors
// --------------------------------------------------------------------------------------------------------------------

    int TimeSpan::hours() const {
        return hours_;
    }

    int TimeSpan::minutes() const {
        return minutes_;
    }

    int TimeSpan::seconds() const {
        return seconds_;
    }

// --------------------------------------------------------------------------------------------------------------------
// Mutator
// --------------------------------------------------------------------------------------------------------------------

    void TimeSpan::set_time(int hours, int minutes, int seconds) {

    hours_ = hours;
    minutes_ = minutes;
    seconds_ = seconds;
    normalize();
    }

// --------------------------------------------------------------------------------------------------------------------
// Arithmetic Operators
// --------------------------------------------------------------------------------------------------------------------

TimeSpan TimeSpan::operator+(const TimeSpan& rhs) const {
    int h = hours_ + rhs.hours_;
    int m = minutes_ + rhs. minutes_;
    int s = seconds_ + rhs.seconds_;
     return TimeSpan(h,m,s);
}

TimeSpan TimeSpan::operator-(const TimeSpan& rhs) const {
    int h = hours_ - rhs.hours_;
    int m = minutes_ - rhs.minutes_;
    int s = seconds_  - rhs.seconds_;
    return TimeSpan(h,m,s);
}
//Unary Operator
TimeSpan TimeSpan::operator-() const {
    TimeSpan final;
    final.hours_ = - hours_;
    final.minutes_ = - minutes_;
    final.seconds_ = - seconds_;
    return final;
}


TimeSpan& TimeSpan::operator+=(const TimeSpan& rhs) {
    hours_+=rhs.hours_;
    minutes_+=rhs.minutes_;
    seconds_+=rhs.seconds_;
    normalize();
    return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& rhs) {
    hours_ -= rhs.hours_;
    minutes_ -= rhs.minutes_;
    seconds_ -= rhs.seconds_;
    normalize();
    return *this;
}

// --------------------------------------------------------------------------------------------------------------------
// Comparison Operators
// --------------------------------------------------------------------------------------------------------------------
bool TimeSpan::operator==(const TimeSpan& rhs) const {
    if (hours_ == rhs.hours_ &&
        minutes_ == rhs.minutes_ &&
        seconds_ == rhs.seconds_) {
        return true;
    }else {
        return false;
    }
}

bool TimeSpan::operator!=(const TimeSpan& rhs) const {
    if (hours_ != rhs.hours_ ||
        minutes_ != rhs.minutes_ ||
        seconds_ != rhs.seconds_) {
        return true;
    }else {
        return false;
    }
}
bool TimeSpan::operator<(const TimeSpan& rhs) const {
    if (hours_ < rhs.hours_) {
        return true;
    }
    if (hours_ > rhs.hours_) {
        return false;
    }
        if ( minutes_ < rhs.minutes_ ) {
            return true;
        }
       if (minutes_ > rhs.minutes_) {
           return false;
       }
           return seconds_ < rhs.seconds_;
       }

bool TimeSpan::operator<=(const TimeSpan& rhs) const {
    return *this < rhs || *this ==rhs;
}

bool TimeSpan::operator>(const TimeSpan& rhs) const {
    if (hours_ > rhs.hours_) {
        return true;
    }
    if (hours_ < rhs.hours_) {
        return false;
    }
    if (minutes_ > rhs.minutes_) {
        return true;
    }
    if (minutes_ < rhs.minutes_) {
        return false;
    }
    return seconds_ > rhs.seconds_;
}

bool TimeSpan::operator>=(const TimeSpan& rhs) const {
    return *this > rhs || *this == rhs;
}

// --------------------------------------------------------------------------------------------------------------------
// Stream Operators
// --------------------------------------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out, const TimeSpan& ts) {
    out<< "Hours: " << ts.hours_ << ", Minutes: " << ts.minutes_ << ", Seconds: "<<ts.seconds_;
        return out;
        }

std::istream& operator>>(std::istream& in, TimeSpan& ts) {
    in >> ts.hours_ >> ts.minutes_ >> ts.seconds_;
    return in;
}








