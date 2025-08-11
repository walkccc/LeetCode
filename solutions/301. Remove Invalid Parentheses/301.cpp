class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    const auto [l, r] = getLeftAndRightCounts(s);
    dfs(s, 0, l, r, ans);
    return ans;
  }

 private:
  // Similar to 921. Minimum Add to Make Parentheses Valid
  // Returns how many '(' and ')' need to be deleted.
  pair<int, int> getLeftAndRightCounts(const string& s) {
    int l = 0;
    int r = 0;

    for (const char c : s)
      if (c == '(')
        ++l;
      else if (c == ')') {
        if (l == 0)
          ++r;
        else
          --l;
      }

    return {l, r};
  }

  void dfs(const string& s, int start, int l, int r, vector<string>& ans) {
    if (l == 0 && r == 0 && isValid(s)) {
      ans.push_back(s);
      return;
    }

    for (int i = start; i < s.length(); ++i) {
      if (i > start && s[i] == s[i - 1])
        continue;
      if (l > 0 && s[i] == '(')  // Delete s[i].
        dfs(s.substr(0, i) + s.substr(i + 1), i, l - 1, r, ans);
      if (r > 0 && s[i] == ')')  // Delete s[i].
        dfs(s.substr(0, i) + s.substr(i + 1), i, l, r - 1, ans);
    }
  }

  bool isValid(const string& s) {
    int opened = 0;  // the number of '(' - # of ')'
    for (const char c : s) {
      if (c == '(')
        ++opened;
      else if (c == ')')
        --opened;
      if (opened < 0)
        return false;
    }
    return true;  // opened == 0
  }
};
