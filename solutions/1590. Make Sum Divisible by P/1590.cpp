class Solution {
 public:
  int minSubarray(vector<int>& nums, int p) {
    const long sum = accumulate(nums.begin(), nums.end(), 0L);
    const int remainder = sum % p;
    if (remainder == 0)
      return 0;

    unordered_map<int, int> prefixToIndex{{0, -1}};
    int ans = nums.size();
    int prefix = 0;

    for (int i = 0; i < nums.size(); ++i) {
      prefix += nums[i];
      prefix %= p;
      const int target = (prefix - remainder + p) % p;
      if (const auto it = prefixToIndex.find(target);
          it != prefixToIndex.cend())
        ans = min(ans, i - it->second);
      prefixToIndex[prefix] = i;
    }

    return ans == nums.size() ? -1 : ans;
  }
};
