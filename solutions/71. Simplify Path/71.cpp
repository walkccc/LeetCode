class Solution {
 public:
  string simplifyPath(string path) {
    string ans;
    istringstream iss(path);
    vector<string> stack;

    for (string dir; getline(iss, dir, '/');) {
      if (dir.empty() || dir == ".")
        continue;
      if (dir == "..") {
        if (!stack.empty())
          stack.pop_back();
      } else {
        stack.push_back(dir);
      }
    }

    for (const string& s : stack)
      ans += "/" + s;

    return ans.empty() ? "/" : ans;
  }
};
