struct Event {
  int x;
  int y1;
  int y2;
  char type;
  Event(int x, int y1, int y2, char type) : x(x), y1(y1), y2(y2), type(type) {}
};

class Solution {
 public:
  int rectangleArea(vector<vector<int>>& rectangles) {
    constexpr int kMod = 1'000'000'007;

    vector<Event> events;

    for (const vector<int>& r : rectangles) {
      events.emplace_back(r[0], r[1], r[3], 's');
      events.emplace_back(r[2], r[1], r[3], 'e');
    }

    ranges::sort(events,
                 [](const auto& a, const auto& b) { return a.x < b.x; });

    long ans = 0;
    int prevX = 0;
    vector<pair<int, int>> yPairs;

    for (const auto& [currX, y1, y2, type] : events) {
      if (currX > prevX) {
        const int width = currX - prevX;
        ans = (ans + width * getHeight(yPairs)) % kMod;
        prevX = currX;
      }
      if (type == 's') {
        yPairs.emplace_back(y1, y2);
        ranges::sort(yPairs);
      } else {  // type == 'e'
        const auto it =
            find(yPairs.begin(), yPairs.end(), pair<int, int>(y1, y2));
        yPairs.erase(it);
      }
    }

    return ans % kMod;
  }

 private:
  long getHeight(const vector<pair<int, int>>& yPairs) {
    int height = 0;
    int prevY = 0;

    for (const auto& [y1, y2] : yPairs) {
      prevY = max(prevY, y1);
      if (y2 > prevY) {
        height += y2 - prevY;
        prevY = y2;
      }
    }

    return height;
  }
};
