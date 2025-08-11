class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    constexpr int kMax = 50;
    int maxFreq = 0;
    for (int target = 1; target <= kMax; ++target)
      if (target != k)
        maxFreq = max(maxFreq, kadane(nums, target, k));
    return ranges::count(nums, k) + maxFreq;
  }

 private:
  // Returns the maximum achievable frequency of `k` by Kakane's algorithm,
  // where each `target` in subarrays is transformed to `k`.
  int kadane(const vector<int>& nums, int target, int k) {
    int maxSum = 0;
    int sum = 0;
    for (const int num : nums) {
      if (num == target)
        ++sum;
      else if (num == k)
        --sum;
      if (sum < 0)  // Reset if sum becomes negative (Kadane's spirit).
        sum = 0;
      maxSum = max(maxSum, sum);
    }
    return maxSum;
  }
};
