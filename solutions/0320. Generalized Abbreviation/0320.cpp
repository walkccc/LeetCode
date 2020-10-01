class Solution {
 public:
  vector<string> generateAbbreviations(string word) {
    vector<string> ans;
    vector<string> path;

    auto join = [](vector<string>& path) {
      string joined;
      for (const string& s : path)
        joined += s;
      return joined;
    };

    function<void(int, int)> dfs = [&](int i, int count) {
      if (i == word.length()) {
        ans.push_back(join(path) + getCountString(count));
        return;
      }

      // abbreviate word[i]
      dfs(i + 1, count + 1);
      // keep word[i], so consume the count as a string
      path.push_back(getCountString(count) + word[i]);
      dfs(i + 1, 0);  // reset count to 0
      path.pop_back();
    };

    dfs(0, 0);

    return ans;
  }

 private:
  string getCountString(int count) {
    return count > 0 ? to_string(count) : "";
  }
};