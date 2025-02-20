class Solution {
 public:
  bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source,
                        vector<int>& target) {
    unordered_set<long> blockedSet;
    for (const vector<int>& b : blocked)
      blockedSet.insert(hash(b[0], b[1]));

    return dfs(blockedSet, source[0], source[1], hash(target[0], target[1]),
               {}) &&
           dfs(blockedSet, target[0], target[1], hash(source[0], source[1]),
               {});
  }

 private:
  bool dfs(unordered_set<long>& blockedSet, int i, int j, long target,
           unordered_set<long>&& seen) {
    if (i < 0 || i >= 1e6 || j < 0 || j >= 1e6 ||
        blockedSet.contains(hash(i, j)) || seen.contains(hash(i, j)))
      return false;

    seen.insert(hash(i, j));
    if (seen.size() > (1 + 199) * 199 / 2 || hash(i, j) == target)
      return true;
    return dfs(blockedSet, i + 1, j, target, std::move(seen)) ||
           dfs(blockedSet, i - 1, j, target, std::move(seen)) ||
           dfs(blockedSet, i, j + 1, target, std::move(seen)) ||
           dfs(blockedSet, i, j - 1, target, std::move(seen));
  }

  long hash(int i, int j) {
    return (static_cast<long>(i) << 16) + j;
  }
};
