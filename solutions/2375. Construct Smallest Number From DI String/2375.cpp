class Solution {
 public:
  string smallestNumber(string pattern) {
    string ans;
    stack<char> stack{{'1'}};

    for (const char c : pattern) {
      char maxSorFar = stack.top();
      if (c == 'I')
        while (!stack.empty()) {
          maxSorFar = max(maxSorFar, stack.top());
          ans += stack.top(), stack.pop();
        }
      stack.push(maxSorFar + 1);
    }

    while (!stack.empty())
      ans += stack.top(), stack.pop();

    return ans;
  }
};
