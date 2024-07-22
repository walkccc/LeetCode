class Solution {
 public:
  // Similar to 907. Sum of Subarray Minimums
  int validSubarraySize(vector<int>& nums, int threshold) {
    const int n = nums.size();
    // prev[i] := the index k s.t. nums[k] is the previous minimum in nums[0..n)
    vector<int> prev(n, -1);
    // next[i] := the index k s.t. nums[k] is the next minimum in nums[i + 1..n)
    vector<int> next(n, n);
    stack<int> stack;

    for (int i = 0; i < n; ++i) {
      while (!stack.empty() && nums[stack.top()] > nums[i]) {
        const int index = stack.top();
        stack.pop();
        next[index] = i;
      }
      if (!stack.empty())
        prev[i] = stack.top();
      stack.push(i);
    }

    for (int i = 0; i < n; ++i) {
      // the number of `nums` in subarray containing nums[i] >= nums[i]
      const int k = (i - prev[i]) + (next[i] - i) - 1;
      if (nums[i] > threshold / static_cast<double>(k))
        return k;
    }

    return -1;
  }
};
