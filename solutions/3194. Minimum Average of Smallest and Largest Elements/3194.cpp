class Solution {
 public:
  double minimumAverage(vector<int>& nums) {
    constexpr int kMax = 50;
    double ans = kMax;
    int i = 0;
    int j = nums.size() - 1;

    ranges::sort(nums);

    while (i < j)
      ans = min(ans, (nums[i++] + nums[j--]) / 2.0);

    return ans;
  }
};
