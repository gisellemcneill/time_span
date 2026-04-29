#include <iostream>
#include "time_span.h"


using namespace std;

bool CheckValues(const TimeSpan& t, int h, int m, int s) {
    return t.hours() == h && t.minutes() == m && t.seconds() == s;
}

int main() {
    cout << "=== Testing TimeSpan ===" << endl;

    TimeSpan t1(1, 2, 3);
    if (!CheckValues(t1, 1, 2, 3))
        cout << "Constructor (h,m,s) failed" << endl;

    TimeSpan t2(90);
    if (!CheckValues(t2, 0, 1, 30))
        cout << "Constructor (seconds) normalization failed" << endl;

    TimeSpan t3(7, -3);
    if (!CheckValues(t3, 0, 6, 57))
        cout << "Constructor (minutes, seconds) failed" << endl;
    
    TimeSpan sum = t1 + t2;
    if (!CheckValues(sum, 1, 3, 33))
        cout << "operator+ failed" << endl;

    TimeSpan diff = t1 - t2;
    if (!CheckValues(diff, 1, 0, 33))
        cout << "operator- failed" << endl;

    TimeSpan neg = -t1;
    if (!CheckValues(neg, -1, -2, -3))
        cout << "unary operator- failed" << endl;

    TimeSpan assign(0);
    assign += t1;
    if (!CheckValues(assign, 1, 2, 3))
        cout << "operator+= failed" << endl;

    assign -= t2;
    if (!CheckValues(assign, 1, 0, 33))
        cout << "operator-= failed" << endl;

    if (!(t1 == TimeSpan(1, 2, 3)))
        cout << "operator== failed" << endl;

    if (t1 != TimeSpan(1, 2, 3))
        cout << "operator!= failed" << endl;

    cout << "TimeSpan output check:" << endl;
    cout << t1 << endl;

}