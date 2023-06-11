class Solution {
 public:
  vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
    constexpr int kMaxBit = 32;
    unordered_map<int, int> maskToIndex;

    for (int i = 0; i < grid.size(); ++i) {
      const int mask = getMask(grid[i]);
      if (mask == 0)
        return {i};
      for (int prevMask = 1; prevMask < kMaxBit; ++prevMask)
        if ((mask & prevMask) == 0 && maskToIndex.count(prevMask))
          return {maskToIndex[prevMask], i};
      maskToIndex[mask] = i;
    }

    return {};
  }

 private:
  int getMask(const vector<int>& row) {
    int mask = 0;
    for (int i = 0; i < row.size(); ++i)
      if (row[i] == 1)
        mask |= 1 << i;
    return mask;
  }
};
