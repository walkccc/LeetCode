class Solution {
 public:
  vector<string> readBinaryWatch(int num) {
    const vector<int> hours{1, 2, 4, 8};
    const vector<int> minutes{1, 2, 4, 8, 16, 32};

    vector<string> ans;

    function<void(int, int, int, int)> dfs = [&](int n, int s, int h, int m) {
      if (n == 0) {
        string time = to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
        ans.push_back(time);
        return;
      }

      for (int i = s; i < hours.size() + minutes.size(); ++i)
        if (i < 4 && h + hours[i] < 12)
          dfs(n - 1, i + 1, h + hours[i], m);
        else if (i >= 4 && m + minutes[i - 4] < 60)
          dfs(n - 1, i + 1, h, m + minutes[i - 4]);
    };

    dfs(num, 0, 0, 0);

    return ans;
  }
};