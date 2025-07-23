class Solution {
 public:
  long long maxSubarraySum(vector<int>& nums) {
    long ans = ranges::max(nums);
    long prefix = 0;
    long minPrefix = 0;
    // the minimum prefix sum that can have a negative number removed
    long modifiedMinPrefix = 0;
    unordered_map<int, int> count;
    // minPrefixPlusRemoval[num] := the minimum prefix sum plus removed `num`
    unordered_map<int, long> minPrefixPlusRemoval;

    for (const int num : nums) {
      prefix += num;
      ans = max(ans, prefix - modifiedMinPrefix);
      if (num < 0) {
        ++count[num];
        minPrefixPlusRemoval[num] =
            min(minPrefixPlusRemoval[num], minPrefix) + num;
        modifiedMinPrefix =
            min({modifiedMinPrefix, count[num] * static_cast<long>(num),
                 minPrefixPlusRemoval[num]});
      }
      minPrefix = min(minPrefix, prefix);
      modifiedMinPrefix = min(modifiedMinPrefix, minPrefix);
    }

    return ans;
  }
};
