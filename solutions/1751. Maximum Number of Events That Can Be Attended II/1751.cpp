class Solution {
 public:
  int maxValue(vector<vector<int>>& events, int k) {
    vector<vector<int>> mem(events.size(), vector<int>(k + 1, -1));
    ranges::sort(events);
    return maxValue(events, 0, k, mem);
  }

 private:
  // Returns the maximum sum of values that you can receive by attending
  // events[i..n), where k is the maximum number of attendancevents.
  int maxValue(const vector<vector<int>>& events, int i, int k,
               vector<vector<int>>& mem) {
    if (k == 0 || i == events.size())
      return 0;
    if (mem[i][k] != -1)
      return mem[i][k];

    // Binary search `events` to find the first index j
    // s.t. events[j][0] > events[i][1].
    const auto it = upper_bound(
        events.begin() + i, events.end(), events[i][1],
        [](int end, const vector<int>& event) { return event[0] > end; });
    const int j = distance(events.begin(), it);
    return mem[i][k] = max(events[i][2] + maxValue(events, j, k - 1, mem),
                           maxValue(events, i + 1, k, mem));
  }
};
