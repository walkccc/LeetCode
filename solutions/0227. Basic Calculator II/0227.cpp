class Solution {
 public:
  int calculate(string s) {
    stack<int> nums;  // stores nums
    stack<char> ops;  // stores operators

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      if (isdigit(c)) {
        int num = c - '0';
        while (i + 1 < s.length() && isdigit(s[i + 1])) {
          num = num * 10 + (s[i + 1] - '0');
          ++i;
        }
        nums.push(num);
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
  int calculate(char op, int b, int a) {
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

  // return true if priority(op1) >= priority(op2)
  bool compare(char op1, char op2) {
    return op1 == '*' || op1 == '/' || op2 == '+' || op2 == '-';
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
