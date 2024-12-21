class Solution {
 public:
  int daysBetweenDates(string date1, string date2) {
    return abs(daysFrom1971(date1) - daysFrom1971(date2));
  }

 private:
  const vector<int> days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int daysFrom1971(const string& date) {
    const int year = stoi(date1.substr(0, 4));
    const int month = stoi(date1.substr(5, 2));
    const int day = stoi(date1.substr(8, 2));
    int res = 0;
    for (int i = 1971; i < year; ++i)
      res += isLeapYear(i) ? 366 : 365;
    for (int i = 0; i < month; ++i)
      res += days[i];
    if (month > 2 && isLeapYear(year))
      ++res;
    res += day;
    return res;
  }

  bool isLeapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  };
};
