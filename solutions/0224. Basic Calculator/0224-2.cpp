class Solution {
 public:
  int calculate(string s) {
    stack<int> nums;  // stores nums
    stack<char> ops;  // stores operators and parentheses

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      if (isdigit(c)) {
        int num = c - '0';
        while (i + 1 < s.length() && isdigit(s[i + 1])) {
          num = num * 10 + (s[i + 1] - '0');
          ++i;
        }
        nums.push(num);
      } else if (c == '(') {
        ops.push(c);
      } else if (c == ')') {
        while (ops.top() != '(')
          nums.push(calculate(pop(ops), pop(nums), pop(nums)));
        ops.pop();  // remove '('
      } else if (c == '+' || c == '-') {
        while (!ops.empty() && ops.top() != '(')
          nums.push(calculate(pop(ops), pop(nums), pop(nums)));
        ops.push(c);
      }
    }

    while (!ops.empty())
      nums.push(calculate(pop(ops), pop(nums), pop(nums)));

    return nums.top();
  }

 private:
  int calculate(char op, int b, int a) {
    return op == '+' ? a + b : a - b;
  }

  char pop(stack<char>& ops) {
    const char op = ops.top();
    ops.pop();
    return op;
  }

  int pop(stack<int>& nums) {
    const int num = nums.top();
    nums.pop();
    return num;
  }
};
