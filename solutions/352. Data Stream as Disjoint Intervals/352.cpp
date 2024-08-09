class SummaryRanges {
 public:
  void addNum(int val) {
    if (intervals.contains(val))
      return;

    const int lo = lowerKey(val);
    const int hi = higherKey(val);

    // {lo, intervals[lo][1]} + val + {hi, intervals[hi][1]} = {lo,
    // intervals[hi][1]}
    if (lo >= 0 && hi >= 0 && intervals[lo][1] + 1 == val && val + 1 == hi) {
      intervals[lo][1] = intervals[hi][1];
      intervals.erase(hi);
      // {lo, intervals[lo][1]} + val = {lo, val}
      // Prevent adding duplicate entry by using '>=' instead of '=='.
    } else if (lo >= 0 && intervals[lo][1] + 1 >= val) {
      intervals[lo][1] = max(intervals[lo][1], val);
    } else if (hi >= 0 && val + 1 == hi) {
      // val + {hi, intervals[hi][1]} = {val, intervals[hi][1]}
      intervals[val] = {val, intervals[hi][1]};
      intervals.erase(hi);
    } else {
      intervals[val] = {val, val};
    }
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> res;
    for (const auto& [_, interval] : intervals)
      res.push_back(interval);
    return res;
  }

 private:
  map<int, vector<int>> intervals;  // {start: (start, end)}

  // Returns the maximum key in `intervals` < `key`.
  int lowerKey(int key) {
    auto it = intervals.lower_bound(key);
    if (it == intervals.begin())
      return -1;
    return (--it)->first;
  }

  // Returns the minimum key in `intervals` > `key`.
  int higherKey(int key) {
    const auto it = intervals.upper_bound(key);
    if (it == intervals.cend())
      return -1;
    return it->first;
  }
};
