class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    vector<string> path;

    auto join = [](vector<string>& path) {
      string joined;
      for (const string& s : path)
        joined += s;
      return joined;
    };

    // start index, prev value, current evaluated value
    function<void(int, long, long)> dfs = [&](int s, long prev, long eval) {
      if (s == num.length()) {
        if (eval == target)
          ans.push_back(join(path));
        return;
      }

      for (int i = s; i < num.length(); ++i) {
        if (i > s && num[s] == '0') break;
        const string& str = num.substr(s, i - s + 1);
        const long curr = stol(str);
        if (s == 0) {  // first num
          path.push_back(str);
          dfs(i + 1, curr, curr);
          path.pop_back();
        } else {
          for (const string& op : {"+", "-", "*"}) {
            path.push_back(op + str);
            if (op == "+")
              dfs(i + 1, curr, eval + curr);
            else if (op == "-")
              dfs(i + 1, -curr, eval - curr);
            else
              dfs(i + 1, prev * curr, eval - prev + prev * curr);
            path.pop_back();
          }
        }
      }
    };

    dfs(0, 0, 0);

    return ans;
  }
};