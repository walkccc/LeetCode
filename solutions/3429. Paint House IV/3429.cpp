class Solution {
 public:
  long long minCost(int n, vector<vector<int>>& costs) {
    constexpr int kInvalidColor = 3;
    vector<vector<vector<long>>> mem(
        n / 2, vector<vector<long>>(4, vector<long>(4, -1)));
    return minCost(costs, 0, kInvalidColor, kInvalidColor, mem);
  }

 private:
  long minCost(const vector<vector<int>>& costs, int i, int prevLeftColor,
               int prevRightColor, vector<vector<vector<long>>>& mem) {
    if (i == costs.size() / 2)
      return 0;
    if (mem[i][prevLeftColor][prevRightColor] != -1)
      return mem[i][prevLeftColor][prevRightColor];

    long res = LONG_MAX;

    for (const int leftColor : getValidColors(prevLeftColor))
      for (const int rightColor : getValidColors(prevRightColor)) {
        if (leftColor == rightColor)
          continue;
        const long leftCost = costs[i][leftColor];
        const long rightCost = costs[costs.size() - 1 - i][rightColor];
        res = min(res, leftCost + rightCost +
                           minCost(costs, i + 1, leftColor, rightColor, mem));
      }

    return mem[i][prevLeftColor][prevRightColor] = res;
  }

  vector<int> getValidColors(int prevColor) {
    vector<int> validColors;
    for (int color = 0; color < 3; ++color)
      if (color != prevColor)
        validColors.push_back(color);
    return validColors;
  }
};
