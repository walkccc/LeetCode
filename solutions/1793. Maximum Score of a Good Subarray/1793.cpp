class Solution {
 public:
  // Similar to 84. Largest Rectangle in Histogram
  int maximumScore(vector<int>& nums, int k) {
    int ans = 0;
    stack<int> stack;

    for (int i = 0; i <= nums.size(); ++i) {
      while (!stack.empty() &&
             (i == nums.size() || nums[stack.top()] > nums[i])) {
        const int h = nums[stack.top()];
        stack.pop();
        const int w = stack.empty() ? i : i - stack.top() - 1;
        if ((stack.empty() || stack.top() + 1 <= k) && i - 1 >= k)
          ans = max(ans, h * w);
      }
      stack.push(i);
    }

    return ans;
  }
};
