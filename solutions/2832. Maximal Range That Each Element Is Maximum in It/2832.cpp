class Solution {
 public:
  vector<int> maximumLengthOfRanges(vector<int>& nums) {
    vector<int> ans(nums.size());
    stack<int> stack;  // a decreasing stack

    for (int i = 0; i <= nums.size(); ++i) {
      while (!stack.empty() &&
             (i == nums.size() || nums[stack.top()] < nums[i])) {
        const int index = stack.top();
        stack.pop();
        const int left = stack.empty() ? -1 : stack.top();
        ans[index] = i - left - 1;
      }
      stack.push(i);
    }

    return ans;
  }
};
