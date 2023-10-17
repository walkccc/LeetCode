class Solution {
 public:
  int minCostSetTime(int startAt, int moveCost, int pushCost,
                     int targetSeconds) {
    int ans = INT_MAX;
    int mins = targetSeconds > 5999 ? 99 : targetSeconds / 60;
    int secs = targetSeconds - mins * 60;

    auto getCost = [&](int mins, int secs) -> int {
      int cost = 0;
      char curr = '0' + startAt;
      for (const char c : to_string(mins * 100 + secs))
        if (c == curr) {
          cost += pushCost;
        } else {
          cost += moveCost + pushCost;
          curr = c;
        }
      return cost;
    };

    while (secs < 100) {
      ans = min(ans, getCost(mins, secs));
      --mins;
      secs += 60;
    }

    return ans;
  }
};
