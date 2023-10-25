struct Event {
  int time;
  int value;
  bool isStart;
  Event(int time, int value, bool isStart)
      : time(time), value(value), isStart(isStart) {}
};

class Solution {
 public:
  int maxTwoEvents(vector<vector<int>>& events) {
    int ans = 0;
    int maxValue = 0;
    vector<Event> evts;

    for (const auto& event : events) {
      const int start = event[0];
      const int end = event[1];
      const int value = event[2];
      evts.emplace_back(start, value, true);
      evts.emplace_back(end + 1, value, false);
    }

    ranges::sort(evts, [](const auto& a, const auto& b) {
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
