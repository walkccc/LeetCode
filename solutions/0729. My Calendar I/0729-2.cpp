class MyCalendar {
 public:
  bool book(int start, int end) {
    auto lo = timeline.lower_bound(end);

    if (lo == begin(timeline) || (--lo)->second <= start) {
      timeline[start] = end;
      return true;
    }

    return false;
  }

 private:
  map<int, int> timeline;
};
