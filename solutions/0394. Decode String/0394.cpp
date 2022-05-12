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
          currStr = prevStr + getRepeatedStr(currStr, n);
        } else {
          currStr += c;
        }
      }

    return currStr;
  }

 private:
  // s * n times
  string getRepeatedStr(const string& s, int n) {
    string repeat;
    while (n--)
      repeat += s;
    return repeat;
  }
};
