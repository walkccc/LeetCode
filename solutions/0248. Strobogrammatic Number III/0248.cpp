class Solution {
 public:
  int strobogrammaticInRange(string low, string high) {
    int ans = 0;

    for (int n = low.length(); n <= high.length(); ++n) {
      string s(n, ' ');
      dfs(low, high, s, 0, n - 1, ans);
    }

    return ans;
  }

 private:
  const vector<pair<char, char>> pairs{
      {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

  void dfs(const string& low, const string& high, string& s, int l, int r,
           int& ans) {
    if (l > r) {
      if (s.length() == low.length() && s < low)
        return;
      if (s.length() == high.length() && s > high)
        return;
      ++ans;
      return;
    }

    for (const auto& [leftDigit, rightDigit] : pairs) {
      if (l == r && leftDigit != rightDigit)
        continue;
      s[l] = leftDigit;
      s[r] = rightDigit;
      if (s.length() > 1 && s[0] == '0')
        continue;
      dfs(low, high, s, l + 1, r - 1, ans);
    }
  }
};
