class MyCalendar {
 public:
  bool book(int start, int end) {
    auto lo = ranges.lower_bound(end);

    if (lo == begin(ranges) || (--lo)->second <= start) {
      ranges[start] = end;
      return true;
    }

    return false;
  }

 private:
  map<int, int> ranges;
};
