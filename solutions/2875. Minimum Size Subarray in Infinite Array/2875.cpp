class Solution {
 public:
  int minSizeSubarray(vector<int>& nums, int target) {
    const long sum = accumulate(nums.begin(), nums.end(), 0L);
    const int n = nums.size();
    const int remainingTarget = target % sum;
    const int repeatLength = (target / sum) * n;
    if (remainingTarget == 0)
      return repeatLength;

    int suffixPlusPrefixLength = n;
    long prefix = 0;
    unordered_map<long, int> prefixToIndex{{0, -1}};

    for (int i = 0; i < 2 * n; ++i) {
      prefix += nums[i % n];
      if (const auto it = prefixToIndex.find(prefix - remainingTarget);
          it != prefixToIndex.cend())
        suffixPlusPrefixLength = min(suffixPlusPrefixLength, i - it->second);
      prefixToIndex[prefix] = i;
    }

    return suffixPlusPrefixLength == n ? -1
                                       : suffixPlusPrefixLength + repeatLength;
  }
};
