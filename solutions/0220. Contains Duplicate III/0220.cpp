class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long> window;

    for (int i = 0; i < nums.size(); ++i) {
      const auto it = window.lower_bound((long)nums[i] - t);
      if (it != cend(window) && *it - nums[i] <= t)
        return true;
      window.insert(nums[i]);
      if (i >= k)
        window.erase(nums[i - k]);
    }

    return false;
  }
};
