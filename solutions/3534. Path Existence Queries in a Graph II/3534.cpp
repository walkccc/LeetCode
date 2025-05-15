class Solution {
 public:
  vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                   vector<vector<int>>& queries) {
    vector<int> ans;
    vector<int> sortedNums;
    vector<int> indexMap(n);
    vector<pair<int, int>> sortedNumAndIndexes;

    for (int i = 0; i < n; ++i)
      sortedNumAndIndexes.emplace_back(nums[i], i);

    ranges::sort(sortedNumAndIndexes);

    for (int i = 0; i < n; ++i) {
      const auto& [num, sortedIndex] = sortedNumAndIndexes[i];
      sortedNums.push_back(num);
      indexMap[sortedIndex] = i;
    }

    const int maxLevel = std::bit_width(static_cast<unsigned>(n)) + 1;
    // jump[i][j] := the index of the j-th ancestor of i
    vector<vector<int>> jump(n, vector<int>(maxLevel));

    int right = 0;
    for (int i = 0; i < n; ++i) {
      while (right + 1 < n && sortedNums[right + 1] - sortedNums[i] <= maxDiff)
        ++right;
      jump[i][0] = right;
    }

    for (int level = 1; level < maxLevel; ++level)
      for (int i = 0; i < n; ++i) {
        const int prevJump = jump[i][level - 1];
        jump[i][level] = jump[prevJump][level - 1];
      }

    for (const vector<int>& query : queries) {
      const int u = query[0];
      const int v = query[1];
      const int uIndex = indexMap[u];
      const int vIndex = indexMap[v];
      const int start = min(uIndex, vIndex);
      const int end = max(uIndex, vIndex);
      const int res = minJumps(jump, start, end, maxLevel - 1);
      ans.push_back(res == INT_MAX ? -1 : res);
    }

    return ans;
  }

 private:
  // Returns the minimum number of jumps from `start` to `end` using binary
  // lifting.
  int minJumps(const vector<vector<int>>& jump, int start, int end, int level) {
    if (start == end)
      return 0;
    if (jump[start][0] >= end)
      return 1;
    if (jump[start][level] < end)
      return INT_MAX;
    int j = level;
    for (; j >= 0; --j)
      if (jump[start][j] < end)
        break;
    return (1 << j) + minJumps(jump, jump[start][j], end, j);
  }
};
