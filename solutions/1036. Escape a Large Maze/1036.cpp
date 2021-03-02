class Solution {
 public:
  bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source,
                        vector<int>& target) {
    unordered_set<long> blockedSet;

    for (vector<int>& b : blocked)
      blockedSet.insert(hash(b[0], b[1]));

    unordered_set<long> visited1;
    unordered_set<long> visited2;

    return dfs(blockedSet, source[0], source[1], hash(target[0], target[1]),
               visited1) &&
           dfs(blockedSet, target[0], target[1], hash(source[0], source[1]),
               visited2);
  }

 private:
  bool dfs(unordered_set<long>& blockedSet, int i, int j, long target,
           unordered_set<long>& visited) {
    if (i < 0 || i >= 1e6 || j < 0 || j >= 1e6 ||
        blockedSet.count(hash(i, j)) || visited.count(hash(i, j)))
      return false;

    visited.insert(hash(i, j));
    if (visited.size() > (1 + 199) * 199 / 2 || hash(i, j) == target)
      return true;

    return dfs(blockedSet, i + 1, j, target, visited) ||
           dfs(blockedSet, i - 1, j, target, visited) ||
           dfs(blockedSet, i, j + 1, target, visited) ||
           dfs(blockedSet, i, j - 1, target, visited);
  }

  long hash(int i, int j) {
    return ((long)i << 16) + j;
  }
};
