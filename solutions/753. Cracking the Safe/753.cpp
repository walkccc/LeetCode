class Solution {
 public:
  string crackSafe(int n, int k) {
    string ans(n, '0');
    dfs(pow(k, n), n, k, {ans}, ans);
    return ans;
  }

 private:
  bool dfs(int passwordSize, int n, int k, unordered_set<string>&& seen,
           string& path) {
    if (seen.size() == passwordSize)
      return true;

    string prefix = path.substr(path.length() - n + 1);

    for (char c = '0'; c < '0' + k; ++c) {
      prefix.push_back(c);
      if (!seen.count(prefix)) {
        seen.insert(prefix);
        path.push_back(c);
        if (dfs(passwordSize, n, k, move(seen), path))
          return true;
        path.pop_back();
        seen.erase(prefix);
      }
      prefix.pop_back();
    }

    return false;
  }
};
