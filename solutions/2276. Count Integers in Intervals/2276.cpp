class CountIntervals {
 public:
  void add(int left, int right) {
    while (isOverlapped(left, right)) {
      auto it = prev(intervals.upper_bound(right));
      const int l = it->first;
      const int r = it->second;
      left = min(left, l);
      right = max(right, r);
      intervals.erase(l);
      cnt -= r - l + 1;
    }

    intervals[left] = right;
    cnt += right - left + 1;
  }

  int count() {
    return cnt;
  }

 private:
  map<int, int> intervals;
  int cnt = 0;

  bool isOverlapped(int left, int right) {
    auto it = intervals.upper_bound(right);
    return it != intervals.begin() && prev(it)->second >= left;
  }
};
