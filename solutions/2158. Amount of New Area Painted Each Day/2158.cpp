enum class Type { ENTERING, LEAVING };

struct Event {
  int day;
  int index;
  Type type;
  Event(int day, int index, Type type) : day(day), index(index), type(type) {}
};

class Solution {
 public:
  vector<int> amountPainted(vector<vector<int>>& paint) {
    const int n = paint.size();
    const int minDay = (*min_element(
        begin(paint), end(paint),
        [](const auto& a, const auto& b) { return a[0] < b[0]; }))[0];
    const int maxDay = (*max_element(
        begin(paint), end(paint),
        [](const auto& a, const auto& b) { return a[1] < b[1]; }))[1];
    vector<int> ans(n);
    vector<Event> events;
    // store indices of paint that are available now
    set<int> runningIndices;

    for (int i = 0; i < n; ++i) {
      const int start = paint[i][0];
      const int end = paint[i][1];
      events.emplace_back(start, i, Type::ENTERING);  // 1 := entering
      events.emplace_back(end, i, Type::LEAVING);     // -1 := leaving
    }

    sort(begin(events), end(events),
         [](const auto& a, const auto& b) { return a.day < b.day; });

    int i = 0;  // events' index
    for (int day = minDay; day < maxDay; ++day) {
      while (i < events.size() && events[i].day == day) {
        if (events[i].type == Type::ENTERING)
          runningIndices.insert(events[i].index);
        else
          runningIndices.erase(events[i].index);
        ++i;
      }
      if (!runningIndices.empty())
        ++ans[*begin(runningIndices)];
    }

    return ans;
  }
};
