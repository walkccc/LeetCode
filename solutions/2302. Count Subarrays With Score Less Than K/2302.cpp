class Solution {
 public:
  long long countSubarrays(vector<int>& nums, long long k) {
    long long ans = 0;
    long long sum = 0;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      sum += nums[r];
      while (sum * (r - l + 1) >= k)
        sum -= nums[l++];
      ans += r - l + 1;
    }

    return ans;
  }
};
