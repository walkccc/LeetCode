class Solution {
 public:
  long long largestEvenSum(vector<int>& nums, int k) {
    ranges::sort(nums);
    long sum = accumulate(nums.end() - k, nums.end(), 0L);
    if (sum % 2 == 0)
      return sum;

    int minOdd = -1;
    int minEven = -1;
    int maxOdd = -1;
    int maxEven = -1;

    for (int i = nums.size() - 1; i + k >= nums.size(); --i)
      if (nums[i] % 2 == 1)
        minOdd = nums[i];
      else
        minEven = nums[i];

    for (int i = 0; i + k < nums.size(); ++i)
      if (nums[i] % 2 == 1)
        maxOdd = nums[i];
      else
        maxEven = nums[i];

    long ans = -1;

    if (maxEven >= 0 && minOdd >= 0)
      ans = max(ans, sum + maxEven - minOdd);
    if (maxOdd >= 0 && minEven >= 0)
      ans = max(ans, sum + maxOdd - minEven);
    return ans;
  }
};
