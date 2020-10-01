class Solution {
 public:
  vector<string> restoreIpAddresses(const string& s) {
    vector<string> ans;
    vector<string> path;

    function<void(int)> dfs = [&](int start) {
      if (path.size() == 4 && start == s.length()) {
        ans.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
        return;
      }
      if (path.size() == 4 || start == s.length()) return;

      for (int length = 1; length <= 3; ++length) {
        if (start + length > s.length()) return;    // out of bound
        if (length > 1 && s[start] == '0') return;  // leading '0'
        const string& num = s.substr(start, length);
        if (stoi(num) > 255) return;
        path.push_back(num);
        dfs(start + length);
        path.pop_back();
      }
    };

    dfs(0);

    return ans;
  }
};