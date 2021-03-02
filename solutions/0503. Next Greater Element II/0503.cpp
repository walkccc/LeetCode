class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> ans(nums.size(), -1);
    stack<int> stack;  // decreasing stack storing indices

    for (int i = 0; i < nums.size() * 2; ++i) {
      const int num = nums[i % nums.size()];
      while (!stack.empty() && nums[stack.top()] < num)
        ans[stack.top()] = num, stack.pop();
      if (i < nums.size())
        stack.push(i);
    }

    return ans;
  }
};
