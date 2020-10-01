class MyCalendar {
 public:
  bool book(int start, int end) {
    auto it = ranges.lower_bound(start);  // the 1st element >= start
    if (it != cend(ranges) && it->first < end) return false;
    if (it != cbegin(ranges) && (--it)->second > start) return false;
    ranges[start] = end;
    return true;
  }

 private:
  map<int, int> ranges;
};