#include <iostream>
#include <string>
using namespace std;

bool leapyearcheck(int y) {
    if (y % 400 == 0)
        return true;
    else if (y % 100 == 0)
        return false;
    else if (y % 4 == 0)
        return true;
    return false;
}
const int monthmask[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
class date {
protected:
    int _y;
    unsigned short _m;
    short _d;
public:
    date() { this->readdate(); }
    date(int y, unsigned short m, unsigned short d) : _y(y), _m(m), _d(d) { this->correctdate(); }
    date(tm* date) : _y(date->tm_year + 1900), _m(date->tm_mon + 1), _d(date->tm_mday) { }
    date(const date& A) { _y = A.getyear(); _m = A.getmonth(); _d = A.getday(); }

    date& operator++();
    date& operator--();
    date& operator++(int);
    date& operator--(int);
    date& operator+(int d);
    date& operator+=(int d);
    date& operator-(int d);
    int operator-(const date& date);
    date& operator-=(int d);
    date& operator=(const date& A);
    date& operator=(tm* tdate);
    bool operator!=(tm* tdate) const;
    bool operator==(tm* tdate) const;
    bool operator>(tm* tdate) const;
    bool operator<(tm* tdate) const;
    bool operator<=(tm* tdate) const;
    bool operator>=(tm* tdate) const;
    bool operator!=(const date& A) const;
    bool operator==(const date& A) const;
    bool operator>(const date& A) const;
    bool operator<(const date& A) const;
    bool operator<=(const date& A) const;
    bool operator>=(const date& A) const;
    operator int() const;
    operator string() const;


    date& todate(tm* date);
    void correctdate();
    void readdate();
    char* dayofweek() const;
    void setdate(int y, unsigned short m, unsigned short d);
    void setyear(int y);
    void setmonth(unsigned short m);
    void setday(unsigned short d);
    int getyear() const;
    unsigned short getmonth() const;
    unsigned short getday() const;
};

char* date::dayofweek() const
{
    int a, y, m, R;
    a = (14 - _m) / 12;
    y = _y - a;
    m = _m + 12 * a - 2;
    R = 7000 + (_d + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
    switch (R % 7) {
    case 1:
        return _strdup("Monday");
    case 2:
        return _strdup("Tuesday");
    case 3:
        return _strdup("Wednesday");
    case 4:
        return _strdup("Thurthday");
    case 5:
        return _strdup("Friday");
    case 6:
        return _strdup("Saturday");
    case 7:
        return _strdup("Sunday");
    default:
        return nullptr;
    }
}

void date::setdate(int y, unsigned short m, unsigned short d)
{
    this->setyear(y);
    this->setmonth(m);
    this->setday(d);
}
void date::setyear(int y)
{
    _y = y;
}
void date::setmonth(unsigned short m)
{
    _m = m;
}
void date::setday(unsigned short d)
{
    _d = d;
}

date& date::todate(tm* date)
{
    _d = date->tm_mday;
    _m = date->tm_mon + 1;
    _y = date->tm_year + 1900;
    return *this;
}

date::operator int() const
{
    int a = 14 - _m / 12;
    int y = _y + 4800 - a;
    int m = _m + 12 * a - 3;
    int d = _d + ((153 * _m) / 5) + (365 * y) + (y / 4) - (y / 100) + (y / 400) - 32045;
    return d;
}
int date::operator-(const date& date)
{
    return abs(int(*this) - int(date));
}
date::operator string() const
{
    return string((_d < 10 ? "0" : "") + to_string(_d) + (_m < 10 ? "/0" : "/") + to_string(_m) + "/" + to_string(_y));
}
ostream& operator<<(ostream& out, date A) {
    out << (A.getday() < 10 ? "0" : "") << A.getday() << '/' << (A.getmonth() < 10 ? "0" : "") << A.getmonth() << '/' << A.getyear();
    return out;
}
istream& operator>>(istream& in, date& A)
{
    int d, m, y;
    cout << "Enter date in format dd/mm/yy: ";
    scanf_s("%d/%d/%d", &d, &m, &y);
    A.setdate(y, d, m);
    A.correctdate();
    return in;
}

date& date::operator+(int d)
{
    _d += d;
    this->correctdate();
    return *this;
}
date& date::operator+=(int d)
{
    _d += d;
    this->correctdate();
    return *this;
}
date& date::operator-(int d)
{
    _d -= d;
    this->correctdate();
    return *this;
}
date& date::operator-=(int d)
{
    _d -= d;
    this->correctdate();
    return *this;
}
date& date::operator--()
{
    _d--;
    this->correctdate();
    return *this;
}
date& date::operator++() {
    _d++;
    this->correctdate();
    return *this;
}
date& date::operator--(int)
{
    _d--;
    this->correctdate();
    return *this;
}
date& date::operator++(int) {
    _d++;
    this->correctdate();
    return *this;
}

bool date::operator!=(const date& A) const
{
    if (_y != A._y and _m != A._m and _d != A._d)
        return true;
    return false;
}
bool date::operator==(const date& A) const
{
    if (_y == A._y and _m == A._m and _d == A._d)
        return true;
    return false;
}
bool date::operator>(const date& A) const
{
    if (_y > A._y or _y == A._y and _m > A._m or _y == A._y and _m == A._m and _d > A._d)
        return true;
    return false;
}
bool date::operator>=(const date& A) const
{
    return (*this > A or *this == A);
}
bool date::operator<(const date& A) const
{
    return !(*this > A);
}
bool date::operator<=(const date& A) const
{
    return (*this < A or *this == A);
}
bool date::operator!=(tm* tdate) const
{
    date temp;
    temp.todate(tdate);
    return(*this != temp);
}
bool date::operator==(tm* tdate) const
{
    date temp;
    temp.todate(tdate);
    return(*this == temp);
}
bool date::operator>(tm* tdate) const
{
    date temp;
    temp.todate(tdate);
    return(*this > temp);
}
bool date::operator>=(tm* tdate) const
{
    date temp;
    temp.todate(tdate);
    return(*this > temp);
}
bool date::operator<(tm* tdate) const
{
    date temp;
    temp.todate(tdate);
    return(*this < temp);
}
bool date::operator<=(tm* tdate) const
{
    date temp;
    temp.todate(tdate);
    return(*this <= temp);
}
date& date::operator=(const date& A)
{
    if (&A != this) {
        _y = A._y;
        _m = A._m;
        _d = A._d;
    }
    return *this;
}
date& date::operator=(tm* tdate)
{
    this->todate(tdate);
    this->correctdate();
    return *this;
}
void date::correctdate()
{
    if (_d > (leapyearcheck(_y) and _m == 2 ? 29 : monthmask[_m - 1])) {
        while (_d > (leapyearcheck(_y) and _m == 2 ? 29 : monthmask[_m - 1])) {
            _d -= monthmask[_m - 1];
            if (_m < 12)
                _m++;
            else {
                while (_m > 12) {
                    _m -= 12;
                    _y++;
                }

            }
        }
        return;
    }
    else if (_d <= 0) {
        while (_d <= 0) {
            if (leapyearcheck(_y) and _m == 2)
                _d += 29;
            else
                _d += monthmask[_m - 1];
            if (_m > 1)
                _m--;
            else {
                _m = 12;
                _y--;
            }
        }
    }
}

void date::readdate()
{
    time_t t = time(nullptr);
    tm* now = new tm();
    localtime_s(now, &t);
    this->todate(now);
}

int date::getyear() const
{
    return _y;
}

unsigned short date::getmonth() const
{
    return _m;
}

unsigned short date::getday() const
{
    return _d;
}