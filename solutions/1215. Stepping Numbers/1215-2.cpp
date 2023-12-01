class Solution {
 public:
  vector<int> countSteppingNumbers(int low, int high) {
    vector<int> ans;
    if (low == 0)
      ans.push_back(0);

    for (int i = 1; i <= 9; ++i)
      dfs(i, low, high, ans);

    ranges::sort(ans);
    return ans;
  }

 private:
  void dfs(long curr, int low, int high, vector<int>& ans) {
    if (curr > high)
      return;
    if (curr >= low)
      ans.push_back(curr);

    const int lastDigit = curr % 10;
    if (lastDigit > 0)
      dfs(curr * 10 + lastDigit - 1, low, high, ans);
    if (lastDigit < 9)
      dfs(curr * 10 + lastDigit + 1, low, high, ans);
  }
};
