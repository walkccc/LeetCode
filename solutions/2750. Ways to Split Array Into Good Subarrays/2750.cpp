class Solution {
 public:
  int numberOfGoodSubarraySplits(vector<int>& nums) {
    if (ranges::count(nums, 1) == 0)
      return 0;

    constexpr int kMod = 1'000'000'007;
    int prev = -1;  // previous 1's index
    int ans = 1;

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == 1) {
        if (prev != -1)
          ans = ans * static_cast<long>(i - prev) % kMod;
        prev = i;
      }

    return ans;
  }
};
