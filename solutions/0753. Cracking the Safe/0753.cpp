class Solution {
 public:
  string crackSafe(int n, int k) {
    passwordSize = pow(k, n);
    string ans(n, '0');
    unordered_set<string> seen{ans};

    dfs(n, k, seen, ans);

    return ans;
  }

 private:
  int passwordSize;

  bool dfs(int n, int k, unordered_set<string>& seen, string& path) {
    if (seen.size() == passwordSize)
      return true;

    string prefix = path.substr(path.length() - n + 1);

    for (char c = '0'; c < '0' + k; ++c) {
      prefix.push_back(c);
      if (!seen.count(prefix)) {
        seen.insert(prefix);
        path.push_back(c);
        if (dfs(n, k, seen, path))
          return true;
        path.pop_back();
        seen.erase(prefix);
      }
      prefix.pop_back();
    }

    return false;
  }
};

