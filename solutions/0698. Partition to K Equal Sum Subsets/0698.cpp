class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    const int sum = accumulate(begin(nums), end(nums), 0);
    if (sum % k != 0) return false;

    const int t = sum / k;  // each subset's target sum
    const int n = nums.size();

    vector<bool> seen(n);

    function<bool(int, int, int)> dfs = [&](int s, int k, int target) {
      if (k == 0) return true;
      if (target < 0) return false;
      if (target == 0) return dfs(0, k - 1, t);

      for (int i = s; i < n; ++i) {
        if (seen[i]) continue;
        seen[i] = true;
        if (dfs(i + 1, k, target - nums[i])) return true;
        seen[i] = false;
      }

      return false;
    };

    return dfs(0, k, t);
  }
};