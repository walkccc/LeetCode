class Solution {
 public:
  int evaluate(string expression) {
    return evaluate(expression, unordered_map<string, int>());
  }

 private:
  int evaluate(const string& e, unordered_map<string, int> scope) {
    if (isdigit(e[0]) || e[0] == '-')
      return stoi(e);
    if (scope.count(e))
      return scope[e];

    const int spaceIndex = e.find_first_of(' ');
    const string nextExpression =
        e.substr(spaceIndex + 1, e.length() - spaceIndex - 2);  // -2: "()"
    const vector<string> tokens = split(nextExpression);

    // note that e[0] == '('
    if (e[1] == 'm')  // mult
      return evaluate(tokens[0], scope) * evaluate(tokens[1], scope);
    if (e[1] == 'a')  // add
      return evaluate(tokens[0], scope) + evaluate(tokens[1], scope);

    // let
    for (int i = 0; i + 1 < tokens.size(); i += 2)
      scope[tokens[i]] = evaluate(tokens[i + 1], scope);
    return evaluate(tokens.back(), scope);
  };

  vector<string> split(const string& e) {
    vector<string> tokens;
    string s;
    int parenthesis = 0;

    for (const char c : e) {
      if (c == '(')
        ++parenthesis;
      else if (c == ')')
        --parenthesis;
      if (parenthesis == 0 && c == ' ') {
        tokens.push_back(s);
        s = "";
      } else {
        s += c;
      }
    }

    if (!s.empty())
      tokens.push_back(s);
    return tokens;
  }
};
