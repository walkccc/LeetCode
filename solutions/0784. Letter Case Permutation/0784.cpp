class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    dfs(s, 0, ans);
    return ans;
  }

 private:
  void dfs(string& s, int i, vector<string>& ans) {
    if (i == s.length()) {
      ans.push_back(s);
      return;
    }
    if (isdigit(s[i])) {
      dfs(s, i + 1, ans);
      return;
    }

    s[i] = tolower(s[i]);
    dfs(s, i + 1, ans);
    s[i] = toupper(s[i]);
    dfs(s, i + 1, ans);
  }
};
