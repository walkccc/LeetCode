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
          const vector<int>& informTime, unordered_map<int, int>&& mem) {
    if (const auto it = mem.find(i); it != mem.cend())
      return it->second;
    if (i == headID)
      return 0;

    const int parent = manager[i];
    return mem[i] = informTime[parent] +
                    dfs(parent, headID, manager, informTime, std::move(mem));
  }
};
