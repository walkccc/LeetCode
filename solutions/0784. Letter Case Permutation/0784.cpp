class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans;

    dfs(S, 0, ans);

    return ans;
  }

 private:
  void dfs(string& S, int i, vector<string>& ans) {
    if (i == S.length()) {
      ans.push_back(S);
      return;
    }
    if (isdigit(S[i])) {
      dfs(S, i + 1, ans);
      return;
    }

    S[i] = tolower(S[i]);
    dfs(S, i + 1, ans);
    S[i] = toupper(S[i]);
    dfs(S, i + 1, ans);
  }
};
