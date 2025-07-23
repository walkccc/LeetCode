enum class Type { kEntering, kLeaving };

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
    const int minDay = (*ranges::min_element(
        paint, ranges::less{}, [](const vector<int>& p) { return p[0]; }))[0];
    const int maxDay = (*ranges::max_element(
        paint, ranges::less{}, [](const vector<int>& p) { return p[1]; }))[1];
    vector<int> ans(n);
    vector<Event> events;
    // Stores the indices of paints that are available now.
    set<int> runningIndices;

    for (int i = 0; i < n; ++i) {
      const int start = paint[i][0];
      const int end = paint[i][1];
      events.emplace_back(start, i, Type::kEntering);  // 1 := entering
      events.emplace_back(end, i, Type::kLeaving);     // -1 := leaving
    }

    ranges::sort(events,
                 [](const auto& a, const auto& b) { return a.day < b.day; });

    int i = 0;  // events' index
    for (int day = minDay; day < maxDay; ++day) {
      while (i < events.size() && events[i].day == day) {
        if (events[i].type == Type::kEntering)
          runningIndices.insert(events[i].index);
        else
          runningIndices.erase(events[i].index);
        ++i;
      }
      if (!runningIndices.empty())
        ++ans[*runningIndices.begin()];
    }

    return ans;
  }
};
