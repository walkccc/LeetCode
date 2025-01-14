class Solution {
 public:
  string findLexSmallestString(string s, int a, int b) {
    string ans = s;

    dfs(s, a, b, {}, ans);

    return ans;
  }

 private:
  void dfs(string s, int a, int b, unordered_set<string>&& seen, string& ans) {
    if (seen.contains(s))
      return;

    seen.insert(s);
    ans = min(ans, s);

    dfs(add(s, a), a, b, std::move(seen), ans);
    dfs(rotate(s, b), a, b, std::move(seen), ans);
  }

  string add(string& s, int a) {
    for (int i = 1; i < s.length(); i += 2)
      s[i] = '0' + (s[i] - '0' + a) % 10;
    return s;
  }

  string rotate(const string& s, int b) {
    const int n = s.length();
    return s.substr(n - b, n) + s.substr(0, n - b);
  }
};
