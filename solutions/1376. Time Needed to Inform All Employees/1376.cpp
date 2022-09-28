class Solution {
 public:
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    int ans = 0;

    for (int i = 0; i < n; ++i)
      ans = max(ans, dfs(i, headID, manager, informTime, {}));

    return ans;
  }

 private:
  int dfs(int i, int headID, const vector<int>& manager,
          const vector<int>& informTime, unordered_map<int, int>&& memo) {
    if (memo.count(i))
      return memo[i];
    if (i == headID)
      return 0;

    const int parent = manager[i];
    return memo[i] = informTime[parent] +
                     dfs(parent, headID, manager, informTime, move(memo));
  }
};
