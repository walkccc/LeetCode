class MyCalendarTwo {
 public:
  bool book(int start, int end) {
    ++line[start];
    --line[end];

    int activeEvents = 0;

    for (const auto& [_, count] : line) {
      activeEvents += count;
      if (activeEvents > 2) {
        if (--line[start] == 0)
          line.erase(start);
        if (++line[end] == 0)
          line.erase(end);
        return false;
      }
    }

    return true;
  }

 private:
  map<int, int> line;
};
