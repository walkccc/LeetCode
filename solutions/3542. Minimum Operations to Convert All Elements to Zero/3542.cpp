class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int ans = 0;
    stack<int> stack;
    stack.push(0);

    for (const int num : nums) {
      while (!stack.empty() && stack.top() > num)
        stack.pop();
      if (stack.empty() || stack.top() < num) {
        ++ans;
        stack.push(num);
      }
    }

    return ans;
  }
};
