struct Event {
  int time;
  int value;
  bool isStart;
};

class Solution {
 public:
  int maxTwoEvents(vector<vector<int>>& events) {
    int ans = 0;
    int maxValue = 0;
    vector<Event> evts;

    for (const vector<int>& event : events) {
      const int start = event[0];
      const int end = event[1];
      const int value = event[2];
      evts.emplace_back(start, value, true);
      evts.emplace_back(end + 1, value, false);
    }

    ranges::sort(evts, [](const Event& a, const Event& b) {
      return a.time == b.time ? a.isStart < b.isStart : a.time < b.time;
    });

    for (const auto& [_, value, isStart] : evts)
      if (isStart)
        ans = max(ans, value + maxValue);
      else
        maxValue = max(maxValue, value);

    return ans;
  }
};
