class Solution {
 public:
  // Similar to 2104. Sum of Subarray Ranges
  long long minMaxSubarraySum(const vector<int>& nums, int k) {
    const auto [prevGt, nextGt] = getPrevNext(nums, less<>());
    const auto [prevLt, nextLt] = getPrevNext(nums, greater<>());
    return subarraySum(nums, prevGt, nextGt, k) +
           subarraySum(nums, prevLt, nextLt, k);
  }

 private:
  // Returns the sum of all subarrays with a size <= k, The `prev` and `next`
  // arrays are used to store the indices of the nearest numbers that are
  // smaller or larger than the current number, respectively.
  long subarraySum(const vector<int>& nums, const vector<int>& prev,
                   const vector<int>& next, int k) {
    long res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      const int l = min(i - prev[i], k);
      const int r = min(next[i] - i, k);
      const int extra = max(0, l + r - 1 - k);
      res += nums[i] * static_cast<long>(l * r - extra * (extra + 1) / 2);
    }
    return res;
  }

  // Returns `prev` and `next`, that store the indices of the nearest numbers
  // that are smaller or larger than the current number depending on `op`.
  pair<vector<int>, vector<int>> getPrevNext(
      const vector<int>& nums, const function<bool(int, int)>& op) {
    const int n = nums.size();
    vector<int> prev(n, -1);
    vector<int> next(n, n);
    stack<int> stack;
    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && op(nums[stack.top()], nums[i])) {
        const int index = stack.top();
        stack.pop();
        next[index] = i;
      }
      if (!stack.empty())
        prev[i] = stack.top();
      stack.push(i);
    }
    return {prev, next};
  }
};
