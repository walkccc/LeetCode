struct T {
  int sum;
  // the sum of the subarray starting from the first number
  int maxSubarraySumPrefix;
  // the sum of the subarray ending in the last number
  int maxSubarraySumSuffix;
  int maxSubarraySum;
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
    const T left = divideAndConquer(nums, l, m);
    const T right = divideAndConquer(nums, m + 1, r);
    return T{
        .sum = left.sum + right.sum,
        .maxSubarraySumPrefix = max(left.maxSubarraySumPrefix,
                                    left.sum + right.maxSubarraySumPrefix),
        .maxSubarraySumSuffix = max(right.maxSubarraySumSuffix,
                                    right.sum + left.maxSubarraySumSuffix),
        .maxSubarraySum =
            max({left.maxSubarraySum, right.maxSubarraySum,
                 left.maxSubarraySumSuffix + right.maxSubarraySumPrefix}),
    };
  }
};
