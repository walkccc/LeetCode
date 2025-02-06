class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    const int targetSum = accumulate(nums.begin(), nums.end(), 0) - x;
    if (targetSum == 0)
      return nums.size();
    const int maxLen = maxSubArrayLen(nums, targetSum);
    return maxLen == -1 ? -1 : nums.size() - maxLen;
  }

 private:
  // Same as 325. Maximum Size Subarray Sum Equals k
  int maxSubArrayLen(vector<int>& nums, int k) {
    int res = -1;
    int prefix = 0;
    unordered_map<int, int> prefixToIndex{{0, -1}};

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      const int target = prefix - k;
      if (const auto it = prefixToIndex.find(target);
          it != prefixToIndex.cend())
        res = max(res, i - it->second);
      // No need to check the existence of the prefix since it's unique.
      prefixToIndex[prefix] = i;
    }

    return res;
  }
};
