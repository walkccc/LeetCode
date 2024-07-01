class Solution {
 public:
  int closestToTarget(vector<int>& arr, int target) {
    int ans = INT_MAX;
    // all the values of subarrays that end in the previous number
    unordered_set<int> prev;

    for (const int num : arr) {
      unordered_set<int> next{num};
      // Extend each subarray that ends in the previous number. Due to
      // monotonicity of the AND operation, the size of `next` will be at most
      // num.bit_count() + 1.
      for (const int val : prev)
        next.insert(val & num);
      for (const int val : next)
        ans = min(ans, abs(target - val));
      prev = move(next);
    }

    return ans;
  }
};
