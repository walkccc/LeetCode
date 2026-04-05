class Solution {
 public:
  vector<int> splitIntoFibonacci(string num) {
    vector<int> ans;
    dfs(num, 0, ans);
    return ans;
  }

 private:
  bool dfs(const string& num, int s, vector<int>& ans) {
    if (s == num.length() && ans.size() >= 3)
      return true;

    for (int i = s; i < num.length(); ++i) {
      if (num[s] == '0' && i > s)
        break;
      const long val = stol(num.substr(s, i + 1 - s));
      if (val > INT_MAX)
        break;
      if (ans.size() >= 2 &&
          val > ans[ans.size() - 2] + static_cast<long>(ans.back()))
        break;
      if (ans.size() <= 1 ||
          val == ans[ans.size() - 2] + static_cast<long>(ans.back())) {
        ans.push_back(val);
        if (dfs(num, i + 1, ans))
          return true;
        ans.pop_back();
      }
    }

    return false;
  }
};
