class Solution {
 public:
  int countKDifference(vector<int>& nums, int k) {
    constexpr int kMax = 100;
    int ans = 0;
    vector<int> count(kMax + 1);

    for (const int num : nums)
      ++count[num];

    for (int i = k + 1; i <= kMax; ++i)
      ans += count[i] * count[i - k];

    return ans;
  }
};
