class MyCalendarThree {
 public:
  int book(int start, int end) {
    ++timeline[start];
    --timeline[end];

    int ans = 0;
    int k = 0;

    for (const auto& [_, count] : timeline)
      ans = max(ans, k += count);

    return ans;
  }

 private:
  map<int, int> timeline;
};
