class Solution {
 public:
  double largestSumOfAverages(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<vector<double>> mem(n + 1, vector<double>(k + 1));
    vector<double> prefix(n + 1);
    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
    return largestSumOfAverages(nums, n, k, prefix, mem);
  }

 private:
  // Returns the maximum score to partition the first i numbers into k groups.
  double largestSumOfAverages(const vector<int>& nums, int i, int k,
                              const vector<double>& prefix,
                              vector<vector<double>>& mem) {
    if (k == 1)
      return prefix[i] / i;
    if (mem[i][k] > 0)
      return mem[i][k];

    // Try all the possible partitions.
    for (int j = k - 1; j < i; ++j)
      mem[i][k] =
          max(mem[i][k], largestSumOfAverages(nums, j, k - 1, prefix, mem) +
                             (prefix[i] - prefix[j]) / (i - j));

    return mem[i][k];
  }
};
