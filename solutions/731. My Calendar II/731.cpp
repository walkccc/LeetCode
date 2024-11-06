class MyCalendarTwo {
 public:
  bool book(int start, int end) {
    for (const auto& [s, e] : overlaps)
      if (max(start, s) < min(end, e))
        return false;

    for (const auto& [s, e] : ranges) {
      const int ss = max(start, s);
      const int ee = min(end, e);
      if (ss < ee)
        overlaps.emplace_back(ss, ee);
    }

    ranges.emplace_back(start, end);
    return true;
  }

 private:
  vector<pair<int, int>> ranges;
  vector<pair<int, int>> overlaps;
};
