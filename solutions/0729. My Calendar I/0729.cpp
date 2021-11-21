class MyCalendar {
 public:
  bool book(int start, int end) {
    for (const auto& [s, e] : ranges)
      if (max(start, s) < min(end, e))
        return false;
    ranges.emplace_back(start, end);
    return true;
  }

 private:
  vector<pair<int, int>> ranges;
};
