class Solution {
 public:
  int minAbsoluteDifference(vector<int>& nums, int x) {
    int ans = INT_MAX;
    set<int> seen;

    for (int i = x; i < nums.size(); ++i) {
      seen.insert(nums[i - x]);
      // `upper_bound` works as well.
      const auto it = seen.lower_bound(nums[i]);
      if (it != seen.cend())
        ans = min(ans, *it - nums[i]);
      if (it != seen.cbegin())
        ans = min(ans, nums[i] - *prev(it));
    }

    return ans;
  }
};
