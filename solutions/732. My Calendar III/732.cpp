class MyCalendarThree {
 public:
  int book(int start, int end) {
    ++line[start];
    --line[end];

    int ans = 0;
    int activeEvents = 0;

    for (const auto& [_, count] : line) {
      activeEvents += count;
      ans = max(ans, activeEvents);
    }

    return ans;
  }

 private:
  map<int, int> line;
};
