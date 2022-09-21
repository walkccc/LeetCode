class Solution {
 public:
  // very similar to 907. Sum of Subarray Minimums
  int validSubarraySize(vector<int>& nums, int threshold) {
    const int n = nums.size();
    // prev[i] := index k s.t. nums[k] is the prev min in nums[:i]
    vector<int> prev(n, -1);
    // next[i] := index k s.t. nums[k] is the next min in nums[i + 1:]
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
      // # of nums in subarray containing nums[i] >= nums[i]
      const int k = (i - prev[i]) + (next[i] - i) - 1;
      if (nums[i] > threshold / static_cast<double>(k))
        return k;
    }

    return -1;
  }
};
