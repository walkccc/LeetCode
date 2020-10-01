class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    const int sum = accumulate(begin(nums), end(nums), 0);
    int prefixSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (prefixSum == sum - prefixSum - nums[i])
        return i;
      prefixSum += nums[i];
    }

    return -1;
  }
};