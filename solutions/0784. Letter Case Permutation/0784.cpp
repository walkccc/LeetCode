class Solution {
 public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans;

    function<void(int)> dfs = [&](int i) {
      if (i == S.length()) {
        ans.push_back(S);
        return;
      }

      if (isdigit(S[i])) {
        dfs(i + 1);
        return;
      }

      S[i] = tolower(S[i]);
      dfs(i + 1);
      S[i] = toupper(S[i]);
      dfs(i + 1);
    };

    dfs(0);

    return ans;
  }
};