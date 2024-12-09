class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> stack;  // a decreasing stack storing indices

    for (int i = 0; i < n * 2; ++i) {
      const int num = nums[i % n];
      while (!stack.empty() && nums[stack.top()] < num)
        ans[stack.top()] = num, stack.pop();
      if (i < n)
        stack.push(i);
    }

    return ans;
  }
};
