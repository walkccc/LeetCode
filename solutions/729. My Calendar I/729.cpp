class MyCalendar {
 public:
  bool book(int startTime, int endTime) {
    for (const auto& [s, e] : line)
      if (max(startTime, s) < min(endTime, e))
        return false;
    line.emplace_back(startTime, endTime);
    return true;
  }

 private:
  vector<pair<int, int>> line;
};
