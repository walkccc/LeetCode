class MyCalendarTwo {
 public:
  bool book(int start, int end) {
    ++timeline[start];
    --timeline[end];

    int activeEvents = 0;

    for (const auto& [_, count] : timeline) {
      activeEvents += count;
      if (activeEvents > 2) {
        if (--timeline[start] == 0)
          timeline.erase(start);
        if (++timeline[end] == 0)
          timeline.erase(end);
        return false;
      }
    }

    return true;
  }

 private:
  map<int, int> timeline;
};
