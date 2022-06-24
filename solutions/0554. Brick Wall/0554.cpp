class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    int maxCount = 0;
    unordered_map<int, int> count;

    for (const auto& row : wall) {
      int prefix = 0;
      for (int i = 0; i < row.size() - 1; ++i) {
        prefix += row[i];
        maxCount = max(maxCount, ++count[prefix]);
      }
    }

    return wall.size() - maxCount;
  }
};
