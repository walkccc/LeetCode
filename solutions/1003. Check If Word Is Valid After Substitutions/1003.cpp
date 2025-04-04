class Solution {
 public:
  bool isValid(string s) {
    stack<char> stack;

    for (const char c : s)
      if (c == 'c') {
        if (stack.size() < 2)
          return false;
        if (stack.top() != 'b')
          return false;
        stack.pop();
        if (stack.top() != 'a')
          return false;
        stack.pop();
      } else {
        stack.push(c);
      }

    return stack.empty();
  }
};
