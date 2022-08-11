class Solution {
 public:
  vector<string> generatePalindromes(string s) {
    int odd = 0;
    unordered_map<char, int> count;

    // get character occurrence
    for (const char c : s)
      ++count[c];

    // count odd one
    for (const auto& [_, value] : count)
      if (value & 1)
        ++odd;

    // can't form any palindrome
    if (odd > 1)
      return {};

    vector<string> ans;
    vector<char> candidates;
    string mid;

    // get mid and candidates characters
    for (const auto& [key, value] : count) {
      if (value & 1)
        mid += key;
      for (int i = 0; i < value / 2; ++i)
        candidates.push_back(key);
    }

    // backtracking to generate our ans (strings)
    dfs(candidates, mid, vector<bool>(candidates.size()), "", ans);
    return ans;
  }

 private:
  // generate all unique palindromes from candidates
  void dfs(const vector<char>& candidates, const string& mid,
           vector<bool>&& used, string&& path, vector<string>& ans) {
    if (path.length() == candidates.size()) {
      string secondHalf = path;
      reverse(begin(secondHalf), end(secondHalf));
      ans.push_back(path + mid + secondHalf);
      return;
    }

    for (int i = 0; i < candidates.size(); ++i) {
      if (used[i])
        continue;
      if (i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1])
        continue;
      used[i] = true;
      path.push_back(candidates[i]);
      dfs(candidates, mid, move(used), move(path), ans);
      path.pop_back();
      used[i] = false;
    }
  }
};
