class MyCalendar {
 public:
  bool book(int start, int end) {
    auto lo = line.lower_bound(end);

    if (lo == line.begin() || (--lo)->second <= start) {
      line[start] = end;
      return true;
    }

    return false;
  }

 private:
  map<int, int> line;
};
