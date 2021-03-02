class Solution {
 public:
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    int minY = m;
    int minX = n;

    for (const auto& op : ops) {
      minY = min(minY, op[0]);
      minX = min(minX, op[1]);
    }

    return minX * minY;
  }
};
