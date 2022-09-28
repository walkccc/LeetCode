class Solution {
 public:
  long long maximumAlternatingSubarraySum(vector<int>& nums) {
    long long ans = INT_MIN;
    long long even = 0;  // subarray sum starting from an even index
    long long odd = 0;   // subarray sum starting from an odd index

    for (int i = 0; i < nums.size(); ++i) {
      if ((i & 1) == 0)  // must pick
        even += nums[i];
      else  // fresh start or minus
        even = max(0LL, even - nums[i]);
      ans = max(ans, even);
    }

    for (int i = 1; i < nums.size(); ++i) {
      if (i & 1)  // must pick
        odd += nums[i];
      else  // fresh start or minus
        odd = max(0LL, odd - nums[i]);
      ans = max(ans, odd);
    }

    return ans;
  }
};
