class SummaryRanges {
 public:
  void addNum(int val) {
    if (map.count(val))
      return;

    const int lo = lowerKey(val);
    const int hi = higherKey(val);

    // {lo, map[lo][1]} + val + {hi, map[hi][1]} = {lo, map[hi][1]}
    if (lo >= 0 && hi >= 0 && map[lo][1] + 1 == val && val + 1 == hi) {
      map[lo][1] = map[hi][1];
      map.erase(hi);
      // {lo, map[lo][1]} + val = {lo, val}
      // Prevent adding duplicate entry by using '>=' instead of '=='.
    } else if (lo >= 0 && map[lo][1] + 1 >= val) {
      map[lo][1] = max(map[lo][1], val);
    } else if (hi >= 0 && val + 1 == hi) {
      // val + {hi, map[hi][1]} = {val, map[hi][1]}
      map[val] = {val, map[hi][1]};
      map.erase(hi);
    } else {
      map[val] = {val, val};
    }
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> intervals;
    for (const auto& [_, interval] : map)
      intervals.push_back(interval);
    return intervals;
  }

 private:
  map<int, vector<int>> map;  // {start: {start, end}}

  // Returns the maximum in the `map` < `key`.
  int lowerKey(int key) {
    auto it = map.lower_bound(key);
    if (it == map.begin())
      return -1;
    return (--it)->first;
  }

  // Returns the minimum in the `map` > `key`.
  int higherKey(int key) {
    const auto it = map.upper_bound(key);
    if (it == map.cend())
      return -1;
    return it->first;
  }
};
