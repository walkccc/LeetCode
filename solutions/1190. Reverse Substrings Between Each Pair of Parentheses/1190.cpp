class Solution {
 public:
  string reverseParentheses(string s) {
    stack<int> stack;
    string ans;

    for (const char c : s)
      if (c == '(') {
        stack.push(ans.length());
      } else if (c == ')') {
        // Reverse the corresponding substring between ().
        const int j = stack.top();
        stack.pop();
        reverse(begin(ans) + j, end(ans));
      } else {
        ans += c;
      }

    return ans;
  }
};
