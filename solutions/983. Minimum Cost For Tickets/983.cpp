class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int ans = 0;
    queue<pair<int, int>> last7;
    queue<pair<int, int>> last30;

    for (int day : days) {
      while (!last7.empty() && last7.front().first + 7 <= day)
        last7.pop();
      while (!last30.empty() && last30.front().first + 30 <= day)
        last30.pop();
      last7.emplace(day, ans + costs[1]);
      last30.emplace(day, ans + costs[2]);
      ans = min({ans + costs[0], last7.front().second, last30.front().second});
    }

    return ans;
  }
};
