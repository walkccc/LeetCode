class Solution {
 public:
  int maxUniqueSplit(string s) {
    size_t ans = 0;
    unordered_set<string> seen;

    function<void(int)> dfs = [&](int start) {
      if (start == s.length()) {
        ans = max(ans, seen.size());
        return;
      }

      for (int i = 1; start + i <= s.length(); ++i) {
        const string cand = s.substr(start, i);
        if (seen.count(cand)) continue;
        seen.insert(cand);
        dfs(start + i);
        seen.erase(cand);
      }
    };

    dfs(0);

    return ans;
  }
};
