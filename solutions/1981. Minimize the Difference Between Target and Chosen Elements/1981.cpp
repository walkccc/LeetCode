class Solution {
 public:
  int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    const int minSum = getMinSum(mat);
    if (minSum >= target)  // No need to consider any larger combination.
      return minSum - target;

    const int maxSum = getMaxSum(mat);
    vector<vector<int>> mem(mat.size(), vector<int>(maxSum + 1, -1));
    return minimizeTheDifference(mat, 0, 0, target, mem);
  }

 private:
  int minimizeTheDifference(const vector<vector<int>>& mat, int i, int sum,
                            int target, vector<vector<int>>& mem) {
    if (i == mat.size())
      return abs(sum - target);
    if (mem[i][sum] != -1)
      return mem[i][sum];
    int res = INT_MAX;
    for (const int num : mat[i])
      res = min(res, minimizeTheDifference(mat, i + 1, sum + num, target, mem));
    return mem[i][sum] = res;
  }

  int getMinSum(const vector<vector<int>>& mat) {
    return accumulate(mat.begin(), mat.end(), 0,
                      [](int subtotal, const vector<int>& row) {
      return subtotal + ranges::min(row);
    });
  }

  int getMaxSum(const vector<vector<int>>& mat) {
    return accumulate(mat.begin(), mat.end(), 0,
                      [](int subtotal, const vector<int>& row) {
      return subtotal + ranges::max(row);
    });
  }
};
