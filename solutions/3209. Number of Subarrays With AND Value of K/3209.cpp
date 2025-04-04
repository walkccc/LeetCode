class Solution {
 public:
  // Similar to 1521. Find a Value of a Mysterious Function Closest to Target
  long long countSubarrays(vector<int>& nums, int k) {
    long long ans = 0;
    // the counter of all the values of subarrays that end in the previous
    // number
    unordered_map<int, int> prev;

    for (const int num : nums) {
      unordered_map<int, int> curr{{num, 1}};
      // Extend each subarray that ends in the previous number. Due to
      // monotonicity of the AND operation, the size of `curr` will be at most
      // num.bit_count() + 1.
      for (const auto& [val, freq] : prev)
        curr[val & num] += freq;
      ans += curr.contains(k) ? curr[k] : 0;
      prev = std::move(curr);
    }

    return ans;
  }
};
