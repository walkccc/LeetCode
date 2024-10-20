class Solution {
 public:
  long long maximumAlternatingSubarraySum(vector<int>& nums) {
    long ans = INT_MIN;
    long even = 0;  // the subarray sum starting from an even index
    long odd = 0;   // the subarray sum starting from an odd index

    for (int i = 0; i < nums.size(); ++i) {
      if (i % 2 == 0)  // Must pick.
        even += nums[i];
      else  // Start a fresh subarray or subtract `nums[i]`.
        even = max(0L, even - nums[i]);
      ans = max(ans, even);
    }

    for (int i = 1; i < nums.size(); ++i) {
      if (i % 2 == 1)  // Must pick.
        odd += nums[i];
      else  // Start a fresh subarray or subtract `nums[i]`.
        odd = max(0L, odd - nums[i]);
      ans = max(ans, odd);
    }

    return ans;
  }
};
