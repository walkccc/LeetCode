class Solution {
 public:
  int minLength(string s) {
    stack<char> stack;

    for (const char c : s)
      if (c == 'B' && match(stack, 'A'))
        stack.pop();
      else if (c == 'D' && match(stack, 'C'))
        stack.pop();
      else
        stack.push(c);

    return stack.size();
  }

 private:
  bool match(const stack<char>& stack, int c) {
    return !stack.empty() && stack.top() == c;
  }
};
