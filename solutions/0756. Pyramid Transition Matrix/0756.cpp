class Solution {
 public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    unordered_map<string, vector<char>> prefixToBlocks;

    for (const string& a : allowed)
      prefixToBlocks[a.substr(0, 2)].push_back(a[2]);

    function<bool(const string&, const string&, int)> dfs =
        [&](const string& row, const string& nextRow, int i) {
          if (row.length() == 1) return true;
          if (nextRow.length() + 1 == row.length())
            return dfs(nextRow, "", 0);

          for (const char c : prefixToBlocks[row.substr(i, 2)])
            if (dfs(row, nextRow + c, i + 1))
              return true;

          return false;
        };

    return dfs(bottom, "", 0);
  }
};