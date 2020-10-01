class Solution {
 public:
  vector<string> generatePalindromes(string s) {
    int odd = 0;
    unordered_map<char, int> count;

    for (const char c : s) ++count[c];

    for (const auto& [_, value] : count)
      if (value & 1) ++odd;

    if (odd > 1) return {};

    vector<string> ans;
    string path;
    vector<char> candidates;
    string mid;

    for (const auto& [key, value] : count) {
      if (value & 1) mid += key;
      for (int i = 0; i < value / 2; ++i) candidates.push_back(key);
    }

    vector<bool> used(candidates.size());

    function<void()> dfs = [&]() {
      if (path.length() == candidates.size()) {
        string secondHalf = path;
        reverse(begin(secondHalf), end(secondHalf));
        ans.push_back(path + mid + secondHalf);
        return;
      }

      for (int i = 0; i < candidates.size(); ++i) {
        if (used[i]) continue;
        if (i > 0 && candidates[i] == candidates[i - 1] && !used[i]) continue;
        used[i] = true;
        path.push_back(candidates[i]);
        dfs();
        path.pop_back();
        used[i] = false;
      }
    };

    dfs();

    return ans;
  }
};