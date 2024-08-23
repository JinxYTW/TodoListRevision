#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>


namespace date {
    class Date {

    public:
        Date();
        Date(int year, int month, int day);
        Date(const Date& date); 
        
        void setYear(int year);
        void updateMonth(int month);
        void updateDay(int day);

        int getYear() const;
        int getMonth() const;
        int getDay() const;

        void print() const;
        void nextDay();
        void previousDay();

    private:
        int _year;
        int _month;
        int _day;
    };

    bool isValidDate(int year, int month, int day);
    bool isValidDay(int month , int day );
}















#endif // DATE_H