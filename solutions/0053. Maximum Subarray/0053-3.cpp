struct T {
  // the sum of the subarray starting from the first number
  int maxSubarraySumLeft;
  // the sum of the subarray ending in the last number
  int maxSubarraySumRight;
  int maxSubarraySum;
  int sum;
};

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    return divideAndConquer(nums, 0, nums.size() - 1).maxSubarraySum;
  }

 private:
  T divideAndConquer(const vector<int>& nums, int l, int r) {
    if (l == r)
      return {nums[l], nums[l], nums[l], nums[l]};

    const int m = (l + r) / 2;
    const T t1 = divideAndConquer(nums, l, m);
    const T t2 = divideAndConquer(nums, m + 1, r);

    const int maxSubarraySumLeft =
        max(t1.maxSubarraySumLeft, t1.sum + t2.maxSubarraySumLeft);
    const int maxSubarraySumRight =
        max(t1.maxSubarraySumRight + t2.sum, t2.maxSubarraySumRight);
    const int maxSubarraySum =
        max({t1.maxSubarraySumRight + t2.maxSubarraySumLeft, t1.maxSubarraySum,
             t2.maxSubarraySum});
    const int sum = t1.sum + t2.sum;
    return {maxSubarraySumLeft, maxSubarraySumRight, maxSubarraySum, sum};
  }
};
