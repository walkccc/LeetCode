class Solution {
 public:
  string decodeString(string s) {
    stack<pair<string, int>> stack;  // (prevStr, repeatCount)
    string currStr;
    int currNum = 0;

    for (const char c : s)
      if (isdigit(c)) {
        currNum = currNum * 10 + (c - '0');
      } else {
        if (c == '[') {
          stack.emplace(currStr, currNum);
          currStr = "";
          currNum = 0;
        } else if (c == ']') {
          const auto [prevStr, n] = stack.top();
          stack.pop();
          currStr = prevStr + repeat(currStr, n);
        } else {
          currStr += c;
        }
      }

    return currStr;
  }

 private:
  string repeat(const string& s, int n) {
    string res;
    for (int i = 0; i < n; ++i)
      res += s;
    return res;
  }
};
