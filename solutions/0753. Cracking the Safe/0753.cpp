class Solution {
 public:
  string crackSafe(int n, int k) {
    string ans(n, '0');
    const int passwordSize = pow(k, n);
    unordered_set<string> seen{ans};

    function<bool()> dfs = [&]() {
      if (seen.size() == passwordSize) return true;

      string prefix = ans.substr(ans.length() - n + 1);
      for (char c = '0'; c < '0' + k; ++c) {
        prefix.push_back(c);
        if (!seen.count(prefix)) {
          seen.insert(prefix);
          ans.push_back(c);
          if (dfs()) return true;
          ans.pop_back();
          seen.erase(prefix);
        }
        prefix.pop_back();
      }

      return false;
    };

    dfs();

    return ans;
  }
};
