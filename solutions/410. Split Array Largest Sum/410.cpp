class Solution {
 public:
  int splitArray(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<vector<int>> mem(n + 1, vector<int>(k + 1, INT_MAX));
    vector<int> prefix(n + 1);
    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
    return splitArray(nums, n, k, prefix, mem);
  }

 private:
  // Returns the minimum of the maximum sum to split the first i numbers into k
  // groups.
  int splitArray(const vector<int>& nums, int i, int k,
                 const vector<int>& prefix, vector<vector<int>>& mem) {
    if (k == 1)
      return prefix[i];
    if (mem[i][k] < INT_MAX)
      return mem[i][k];

    // Try all the possible partitions.
    for (int j = k - 1; j < i; ++j)
      mem[i][k] = min(mem[i][k], max(splitArray(nums, j, k - 1, prefix, mem),
                                     prefix[i] - prefix[j]));

    return mem[i][k];
  }
};
