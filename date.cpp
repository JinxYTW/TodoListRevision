#include "date.h"

namespace date {
    Date::Date() : _year(0), _month(0), _day(0) {}

    Date::Date(int year, int month, int day)  {
        if (isValidDate(year, month, day)){
            _year = year;
            _month = month;
            _day = day;
        }
        else {
            _year = 0;
            _month = 0;
            _day = 0;
        }
    }

    Date::Date(const Date& date) : _year(date._year), _month(date._month), _day(date._day) {}

    void Date::setYear(int year){
        _year = year;
    }

    void Date::updateMonth(int month){
        if (isValidDay(month, _day)){
            _month = month;
        }
    }

    void Date::updateDay(int day){
        if (isValidDay(_month, day)){
            _day = day;
        }
    }

    int Date::getYear() const {
        return _year;
    }

    int Date::getMonth() const {
        return _month;
    }

    int Date::getDay() const {
        return _day;
    }

    void Date::print() const {
        std::cout << _year << "-" << _month << "-" << _day << std::endl;
    }
    void Date::nextDay(){
        if (_day == 31){
            if (_month == 12){
                _year++;
                _month = 1;
                _day = 1;
            }
            else {
                _month++;
                _day = 1;
            }
        }
        else {
            _day++;
        }
    }

    void Date::previousDay(){
        if (_day == 1){
            if (_month == 1){
                _year--;
                _month = 12;
                _day = 31;
            }
            else {
                _month--;
                _day = 31;
            }
        }
        else {
            _day--;
        }
    }

    bool isValidDate(int year, int month, int day){
        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31){
            return false;
        }
        return true;
    }

    bool isValidDay(int month, int day){
        if (month < 1 || month > 12 || day < 1 || day > 31){
            return false;
        }
        return true;
    }



}
















