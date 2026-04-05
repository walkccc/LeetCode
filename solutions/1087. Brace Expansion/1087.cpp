class Solution {
 public:
  vector<string> expand(string s) {
    vector<string> ans;
    string path;
    dfs(s, 0, path, ans);
    return ans;
  }

 private:
  void dfs(const string& s, int i, string& path, vector<string>& ans) {
    if (i == s.length()) {
      ans.push_back(path);
      return;
    }
    if (s[i] == '{') {
      const int nextRightBraceIndex = s.find_first_of('}', i);
      for (const char c :
           split(s.substr(i + 1, nextRightBraceIndex - i - 1), ',')) {
        path.push_back(c);
        dfs(s, nextRightBraceIndex + 1, path, ans);
        path.pop_back();
      }
    } else {  // s[i] != '{'
      path.push_back(s[i]);
      dfs(s, i + 1, path, ans);
      path.pop_back();
    }
  }

  vector<char> split(const string& s, char delimiter) {
    vector<char> splitted;
    for (const char c : s)
      if (c != delimiter)
        splitted.push_back(c);
    return splitted;
  }
};
