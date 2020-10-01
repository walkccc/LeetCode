class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    int maxCount = 0;
    unordered_map<int, int> count;

    for (const vector<int>& row : wall) {
      int prefixSum = 0;
      for (int i = 0; i < row.size() - 1; ++i) {
        prefixSum += row[i];
        maxCount = max(maxCount, ++count[prefixSum]);
      }
    }

    return wall.size() - maxCount;
  }
};