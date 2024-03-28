class MyCalendar {
 public:
  bool book(int start, int end) {
    for (const auto& [s, e] : timeline)
      if (max(start, s) < min(end, e))
        return false;
    timeline.emplace_back(start, end);
    return true;
  }

 private:
  vector<pair<int, int>> timeline;
};
