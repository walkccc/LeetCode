class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    long long ans = 0;
    long long sum = 0;
    int distinct = 0;
    unordered_map<int, int> count;

    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (++count[nums[i]] == 1)
        ++distinct;
      if (i >= k) {
        if (--count[nums[i - k]] == 0)
          --distinct;
        sum -= nums[i - k];
      }
      if (i >= k - 1 && distinct == k)
        ans = max(ans, sum);
    }

    return ans;
  }
};
