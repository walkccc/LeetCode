class Solution {
 public:
  string removeOuterParentheses(string s) {
    string ans;
    int opened = 0;

    for (const char c : s)
      if (c == '(') {
        if (++opened > 1)
          ans += c;
      } else if (--opened > 0) {  // c == ')'
        ans += c;
      }

    return ans;
  }
};
