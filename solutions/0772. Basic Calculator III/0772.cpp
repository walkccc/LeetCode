class Solution {
 public:
  int calculate(string s) {
    stack<long> nums;  // stores nums
    stack<char> ops;   // stores operators and parentheses

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      if (isdigit(c)) {
        long num = c - '0';
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
      } else if (c == '+' || c == '-' || c == '*' || c == '/') {
        while (!ops.empty() && compare(ops.top(), c))
          nums.push(calculate(pop(ops), pop(nums), pop(nums)));
        ops.push(c);
      }
    }

    while (!ops.empty())
      nums.push(calculate(pop(ops), pop(nums), pop(nums)));

    return nums.top();
  }

 private:
  long calculate(char op, long b, long a) {
    switch (op) {
      case '+':
        return a + b;
      case '-':
        return a - b;
      case '*':
        return a * b;
      case '/':
        return a / b;
    }
    throw;
  }

  // return true if op1 is a operator and priority(op1) >= priority(op2)
  bool compare(char op1, char op2) {
    if (op1 == '(' || op1 == ')')
      return false;
    return op1 == '*' || op1 == '/' || op2 == '+' || op2 == '-';
  }

  char pop(stack<char>& ops) {
    const char op = ops.top();
    ops.pop();
    return op;
  }

  long pop(stack<long>& nums) {
    const long num = nums.top();
    nums.pop();
    return num;
  }
};
