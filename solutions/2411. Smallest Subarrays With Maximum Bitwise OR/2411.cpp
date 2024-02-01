class Solution {
 public:
  vector<int> smallestSubarrays(vector<int>& nums) {
    constexpr int kMaxBit = 30;
    vector<int> ans(nums.size(), 1);
    // closest[j] := the closest index i s.t. the j-th bit of nums[i] is 1
    vector<int> closest(kMaxBit);

    for (int i = nums.size() - 1; i >= 0; --i)
      for (int j = 0; j < kMaxBit; ++j) {
        if (nums[i] >> j & 1)
          closest[j] = i;
        ans[i] = max(ans[i], closest[j] - i + 1);
      }

    return ans;
  }
};
