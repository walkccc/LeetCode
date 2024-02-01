class Solution {
 public:
  long long largestEvenSum(vector<int>& nums, int k) {
    ranges::sort(nums);
    long long sum = accumulate(nums.end() - k, nums.end(), 0LL);
    if (sum % 2 == 0)
      return sum;

    int minOdd = -1;
    int minEven = -1;
    int maxOdd = -1;
    int maxEven = -1;

    for (int i = nums.size() - 1; i + k >= nums.size(); --i)
      if (nums[i] & 1)
        minOdd = nums[i];
      else
        minEven = nums[i];

    for (int i = 0; i + k < nums.size(); ++i)
      if (nums[i] & 1)
        maxOdd = nums[i];
      else
        maxEven = nums[i];

    long long ans = -1;

    if (maxEven >= 0 && minOdd >= 0)
      ans = max(ans, sum + maxEven - minOdd);
    if (maxOdd >= 0 && minEven >= 0)
      ans = max(ans, sum + maxOdd - minEven);
    return ans;
  }
};
