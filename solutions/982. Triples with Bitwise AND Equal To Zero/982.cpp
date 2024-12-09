class Solution {
 public:
  int countTriplets(vector<int>& nums) {
    constexpr int kMax = 1 << 16;
    int ans = 0;
    vector<int> count(kMax);  // {nums[i] & nums[j]: times}

    for (const int a : nums)
      for (const int b : nums)
        ++count[a & b];

    for (const int num : nums)
      for (int i = 0; i < kMax; ++i)
        if ((num & i) == 0)
          ans += count[i];

    return ans;
  }
};
