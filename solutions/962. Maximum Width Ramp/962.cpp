class Solution {
 public:
  int maxWidthRamp(vector<int>& nums) {
    int ans = 0;
    stack<int> stack;

    for (int i = 0; i < nums.size(); ++i)
      if (stack.empty() || nums[i] < nums[stack.top()])
        stack.push(i);

    for (int i = nums.size() - 1; i > ans; --i)
      while (!stack.empty() && nums[i] >= nums[stack.top()])
        ans = max(ans, i - stack.top()), stack.pop();

    return ans;
  }
};
