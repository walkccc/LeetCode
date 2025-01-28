class Solution {
 public:
  vector<int> simulationResult(vector<int>& windows, vector<int>& queries) {
    vector<int> ans;
    unordered_set<int> seen;

    for (int i = queries.size() - 1; i >= 0; --i)
      if (!seen.contains(queries[i])) {
        ans.push_back(queries[i]);
        seen.insert(queries[i]);
      }

    for (const int window : windows)
      if (!seen.contains(window)) {
        ans.push_back(window);
        seen.insert(window);
      }

    return ans;
  }
};
