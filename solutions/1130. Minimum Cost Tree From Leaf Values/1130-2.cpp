class Solution {
 public:
  int mctFromLeafValues(vector<int>& arr) {
    int ans = 0;
    vector<int> stack{INT_MAX};

    for (const int a : arr) {
      while (stack.back() <= a) {
        const int mid = stack.back();
        stack.pop_back();
        // Multiply mid with next greater element in the array,
        // On the left (stack[-1]) or on the right (current number a)
        ans += min(stack.back(), a) * mid;
      }
      stack.push_back(a);
    }

    for (int i = 2; i < stack.size(); ++i)
      ans += stack[i] * stack[i - 1];

    return ans;
  }
};
