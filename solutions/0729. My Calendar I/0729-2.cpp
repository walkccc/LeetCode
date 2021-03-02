class MyCalendar {
 public:
  bool book(int start, int end) {
    auto next = calendar.lower_bound(start);  // 1st element >= start
    if (next != cend(calendar) && next->first < end)
      return false;
    if (next != cbegin(calendar) && (--next)->second > start)
      return false;

    calendar[start] = end;
    return true;
  }

 private:
  map<int, int> calendar;
};
