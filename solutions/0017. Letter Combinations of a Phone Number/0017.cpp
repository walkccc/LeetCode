class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    const vector<string> digitToLetters{"",    "",    "abc",  "def", "ghi",
                                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string path;

    function<void(int)> dfs = [&](int i) {
      if (i == digits.length()) {
        ans.push_back(path);
        return;
      }

      for (const char letter : digitToLetters[digits[i] - '0']) {
        path.push_back(letter);
        dfs(i + 1);
        path.pop_back();
      }
    };

    dfs(0);

    return ans;
  }
};