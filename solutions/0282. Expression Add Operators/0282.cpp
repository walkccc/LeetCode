class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    dfs(num, target, 0, 0, 0, {}, ans);
    return ans;
  }

 private:
  string join(const vector<string>& path) {
    string joined;
    for (const string& s : path)
      joined += s;
    return joined;
  }

  void dfs(const string& num, int target, int start, long prev, long eval,
           vector<string>&& path, vector<string>& ans) {
    if (start == num.length()) {
      if (eval == target)
        ans.push_back(join(path));
      return;
    }

    for (int i = start; i < num.length(); ++i) {
      if (i > start && num[start] == '0')
        return;
      const string& s = num.substr(start, i - start + 1);
      const long curr = stol(s);
      if (start == 0) {
        path.push_back(s);
        dfs(num, target, i + 1, curr, curr, move(path), ans);
        path.pop_back();
      } else {
        for (const string& op : {"+", "-", "*"}) {
          path.push_back(op + s);
          if (op == "+")
            dfs(num, target, i + 1, curr, eval + curr, move(path), ans);
          else if (op == "-")
            dfs(num, target, i + 1, -curr, eval - curr, move(path), ans);
          else
            dfs(num, target, i + 1, prev * curr, eval - prev + prev * curr,
                move(path), ans);
          path.pop_back();
        }
      }
    }
  }
};
