class Solution {
 public:
  int calculate(string s) {
    int ans = 0;
    int num = 0;
    int sign = 1;
    stack<int> stack{{sign}};  // stack.top() := the current environment's sign

    for (const char c : s)
      if (isdigit(c))
        num = num * 10 + (c - '0');
      else if (c == '(')
        stack.push(sign);
      else if (c == ')')
        stack.pop();
      else if (c == '+' || c == '-') {
        ans += sign * num;
        sign = (c == '+' ? 1 : -1) * stack.top();
        num = 0;
      }

    return ans + sign * num;
  }
};
