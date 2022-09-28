class Solution {
 public:
  int calculate(string s) {
    stack<int> nums;
    stack<int> ops;
    bool hasPrevNum = false;

    auto calc = [&]() {
      const int b = nums.top();
      nums.pop();
      const int a = nums.top();
      nums.pop();
      const char op = ops.top();
      ops.pop();
      if (op == '+')
        nums.push(a + b);
      else if (op == '-')
        nums.push(a - b);
      else if (op == '*')
        nums.push(a * b);
      else  // op == '/'
        nums.push(a / b);
    };

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      if (isdigit(c)) {
        int num = c - '0';
        while (i + 1 < s.length() && isdigit(s[i + 1]))
          num = num * 10 + (s[i++ + 1] - '0');
        nums.push(num);
        hasPrevNum = true;
      } else if (c == '(') {
        ops.push('(');
        hasPrevNum = false;
      } else if (c == ')') {
        while (ops.top() != '(')
          calc();
        ops.pop();  // pop '('
      } else if (c == '+' || c == '-' || c == '*' || c == '/') {
        if (!hasPrevNum)
          nums.push(0);
        while (!ops.empty() && precedes(ops.top(), c))
          calc();
        ops.push(c);
      }
    }

    while (!ops.empty())
      calc();

    return nums.top();
  }

 private:
  // return true if prevOp is a operator and
  // priority(prevOp) >= priority(currOp)
  bool precedes(char prevOp, char currOp) {
    if (prevOp == '(')
      return false;
    return prevOp == '*' || prevOp == '/' || currOp == '+' || currOp == '-';
  }
};
