class Solution {
 public:
  int calculate(string s) {
    int num = 0;
    char sign = '+';
    vector<int> stack;

    for (const char c : s + '+')
      if (isdigit(c)) {
        num = num * 10 + (c - '0');
      } else if (isSign(c)) {
        switch (sign) {
          case '+':
            stack.push_back(num);
            break;
          case '-':
            stack.push_back(-num);
            break;
          case '*':
            num = stack.back() * num;
            stack.pop_back();
            stack.push_back(num);
            break;
          default:
            num = stack.back() / num;
            stack.pop_back();
            stack.push_back(num);
        }
        num = 0;
        sign = c;
      }

    return accumulate(begin(stack), end(stack), 0);
  }

 private:
  bool isSign(const char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
  }
};