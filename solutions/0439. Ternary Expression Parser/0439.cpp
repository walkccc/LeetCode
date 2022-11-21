class Solution {
 public:
  string parseTernary(string expression) {
    const char c = expression[i];

    if (i + 1 == expression.length() || expression[i + 1] == ':') {
      i += 2;  // Skip ':'
      return string(1, c);
    }

    i += 2;  // Skip '?'
    const string& first = parseTernary(expression);
    const string& second = parseTernary(expression);
    return c == 'T' ? first : second;
  }

 private:
  int i = 0;
};
