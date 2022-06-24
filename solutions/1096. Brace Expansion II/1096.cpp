class Solution {
 public:
  vector<string> braceExpansionII(string expression) {
    return dfs(expression, 0, expression.length() - 1);
  }

 private:
  vector<string> dfs(const string& expression, int s, int e) {
    set<string> ans;
    vector<vector<string>> groups{{}};
    int layer = 0;
    int left = 0;

    for (int i = s; i <= e; ++i)
      if (expression[i] == '{' && ++layer == 1)
        left = i + 1;
      else if (expression[i] == '}' && --layer == 0)
        merge(groups, dfs(expression, left, i - 1));
      else if (expression[i] == ',' && layer == 0)
        groups.push_back({});
      else if (layer == 0)
        merge(groups, {string(1, expression[i])});

    for (const auto& group : groups)
      for (const string& word : group)
        ans.insert(word);

    return {begin(ans), end(ans)};
  }

  void merge(vector<vector<string>>& groups, const vector<string> group) {
    if (groups.back().empty()) {
      groups[groups.size() - 1] = group;
      return;
    }

    vector<string> mergedGroup;

    for (auto& word1 : groups.back())
      for (auto& word2 : group)
        mergedGroup.push_back(word1 + word2);

    groups[groups.size() - 1] = mergedGroup;
  }
};
