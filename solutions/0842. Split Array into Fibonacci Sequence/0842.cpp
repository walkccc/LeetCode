class Solution {
 public:
  vector<int> splitIntoFibonacci(string S) {
    vector<int> ans;

    dfs(S, 0, ans);

    return ans;
  }

 private:
  bool dfs(const string& S, int s, vector<int>& ans) {
    if (s == S.length() && ans.size() >= 3)
      return true;

    for (int i = s; i < S.length(); ++i) {
      if (S[s] == '0' && i > s)
        break;
      const long num = stol(S.substr(s, i + 1 - s));
      if (num > INT_MAX)
        break;
      if (ans.size() >= 2 && num > (long)ans[ans.size() - 2] + ans.back())
        break;
      if (ans.size() <= 1 || num == (long)ans[ans.size() - 2] + ans.back()) {
        ans.push_back(num);
        if (dfs(S, i + 1, ans))
          return true;
        ans.pop_back();
      }
    }

    return false;
  }
};
