#pragma once
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
namespace ac {
namespace common {

#define DATETIME_FORMAT "%Y-%m-%d %H:%M:%S"
#define DATETIME_FORMAT2 "%Y%m%d%H%M%S"
#define DATE_FORMAT "%Y-%m-%d"

class DateTime {
public:
  DateTime() {
    time_t t = time(nullptr);
    struct tm *now = localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
    hour = now->tm_hour;
    minute = now->tm_min;
    second = now->tm_sec;
  }

  DateTime(int year, int month, int day, int hour, int minute, int second)
      : year(year), month(month), day(day), hour(hour), minute(minute),
        second(second) {}

  int getYear() const { return year; }

  int getMonth() const { return month; }

  int getDay() const { return day; }

  int getHour() const { return hour; }

  int getMinute() const { return minute; }

  int getSecond() const { return second; }

  time_t getTimestamp() const;

  void setYear(int year) { this->year = year; }

  void setMonth(int month) { this->month = month; }

  void setDay(int day) { this->day = day; }

  void setHour(int hour) { this->hour = hour; }

  void setMinute(int minute) { this->minute = minute; }

  void setSecond(int second) { this->second = second; }

  std::string toString(const std::string &format = DATETIME_FORMAT)  const;

  static DateTime parse(const std::string &str , const std::string &format = DATETIME_FORMAT);

private:
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
};

} // namespace common
} // namespace ac
