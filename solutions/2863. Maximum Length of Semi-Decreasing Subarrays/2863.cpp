class Solution {
 public:
  int maxSubarrayLength(vector<int>& nums) {
    int ans = 0;
    stack<int> stack;

    for (int i = nums.size() - 1; i >= 0; --i)
      // If nums[stack.top()] <= nums[i], stack.top() is better than i.
      // So, no need to push it.
      if (stack.empty() || nums[stack.top()] > nums[i])
        stack.push(i);

    for (int i = 0; i < nums.size(); ++i)
      while (!stack.empty() && num > nums[stack.top()])
        ans = max(ans, stack.top() - i + 1), stack.pop();

    return ans;
  }
};
