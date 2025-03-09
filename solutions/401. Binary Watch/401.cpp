class Solution {
 public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> ans;
    dfs(turnedOn, 0, 0, 0, ans);
    return ans;
  }

 private:
  static constexpr int hours[4] = {1, 2, 4, 8};
  static constexpr int minutes[6] = {1, 2, 4, 8, 16, 32};

  void dfs(int turnedOn, int s, int h, int m, vector<string>& ans) {
    if (turnedOn == 0) {
      string time = to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
      ans.push_back(time);
      return;
    }

    for (int i = s; i < 4 + 6; ++i)
      if (i < 4 && h + hours[i] < 12)
        dfs(turnedOn - 1, i + 1, h + hours[i], m, ans);
      else if (i >= 4 && m + minutes[i - 4] < 60)
        dfs(turnedOn - 1, i + 1, h, m + minutes[i - 4], ans);
  }
};
