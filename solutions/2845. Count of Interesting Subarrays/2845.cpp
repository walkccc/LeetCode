class Solution {
 public:
  long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    long ans = 0;
    int prefix = 0;  // (number of nums[i] % modulo == k so far) % modulo
    unordered_map<int, int> prefixCount{{0, 1}};

    for (const int num : nums) {
      if (num % modulo == k)
        prefix = (prefix + 1) % modulo;
      ans += prefixCount[(prefix - k + modulo) % modulo];
      ++prefixCount[prefix];
    }

    return ans;
  }
};
