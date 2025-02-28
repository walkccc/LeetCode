class Solution {
 public:
  int maxScore(vector<vector<int>>& grid) {
    unordered_map<int, unordered_set<int>> numToIndices;
    for (int index = 0; index < grid.size(); ++index)
      for (const int num : grid[index])
        numToIndices[num].insert(index);
    vector<vector<int>> mem(numToIndices.size(), vector<int>(1 << grid.size()));
    return maxScore({numToIndices.begin(), numToIndices.end()}, 0, 0, mem);
  }

 private:
  // Returns the maximum score by selecting numbers from numToIndices[i..],
  // where `mask` is the bitmask of the used row indices.
  int maxScore(const vector<pair<int, unordered_set<int>>>& numToIndices, int i,
               int mask, vector<vector<int>>& mem) {
    if (i == numToIndices.size())
      return 0;
    if (mem[i][mask] != 0)
      return mem[i][mask];
    // Skip numToIndices[i].first.
    int res = maxScore(numToIndices, i + 1, mask, mem);
    for (const int index : numToIndices[i].second)
      if ((mask >> index & 1) == 0)
        // Take numToIndices[i].first.
        res =
            max(res, numToIndices[i].first +
                         maxScore(numToIndices, i + 1, mask | 1 << index, mem));
    return mem[i][mask] = res;
  }
};
