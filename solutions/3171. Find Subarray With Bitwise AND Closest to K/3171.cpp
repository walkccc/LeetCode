class Solution {
 public:
  // Similar to 1521. Find a Value of a Mysterious Function Closest to Target
  int minimumDifference(vector<int>& nums, int k) {
    int ans = INT_MAX;
    // all the values of subarrays that end in the previous number
    unordered_set<int> prev;

    for (const int num : nums) {
      unordered_set<int> next{num};
      // Extend each subarray that ends in the previous number. Due to
      // monotonicity of the OR operation, the size of `next` will be at most
      // num.bit_count() + 1.
      for (const int val : prev)
        next.insert(val | num);
      for (const int val : next)
        ans = min(ans, abs(k - val));
      prev = std::move(next);
    }

    return ans;
  }
};
