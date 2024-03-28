class Solution {
 public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    long long ans = LLONG_MIN;
    long long prefix = 0;
    // {num: the minimum prefix sum excluding `num`}
    unordered_map<int, long long> numToMinPrefix;

    for (const int num : nums) {
      if (const auto it = numToMinPrefix.find(num);
          it == numToMinPrefix.cend() || it->second > prefix) {
        numToMinPrefix[num] = prefix;
      }
      prefix += num;
      if (const auto it = numToMinPrefix.find(num + k);
          it != numToMinPrefix.cend())
        ans = max(ans, prefix - it->second);
      if (const auto it = numToMinPrefix.find(num - k);
          it != numToMinPrefix.cend())
        ans = max(ans, prefix - it->second);
    }

    return ans == LLONG_MIN ? 0 : ans;
  }
};
