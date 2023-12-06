class Poly {
  friend Poly operator+(const Poly& lhs, const Poly& rhs) {
    Poly res(lhs);
    for (const auto& [term, coef] : rhs.terms)
      res.terms[term] += coef;
    return res;
  }

  friend Poly operator-(const Poly& lhs, const Poly& rhs) {
    Poly res(lhs);
    for (const auto& [term, coef] : rhs.terms)
      res.terms[term] -= coef;
    return res;
  }

  friend Poly operator*(const Poly& lhs, const Poly& rhs) {
    Poly res;
    for (const auto& [a, aCoef] : lhs.terms)
      for (const auto& [b, bCoef] : rhs.terms)
        res.terms[merge(a, b)] += aCoef * bCoef;
    return res;
  }

  // Friend ostream& operator<<(ostream& os, const Poly& poly) {
  //   os << "{";
  //   for (const auto& [term, coef] : poly.terms)
  //     os << term << ": " << coef << ", ";
  //   os << "}";
  //   return os;
  // }

 public:
  vector<string> toList() {
    vector<string> res;
    vector<string> keys;
    for (const auto& [term, _] : terms)
      keys.push_back(term);
    ranges::sort(keys, [&](const auto& a, const auto& b) {
      // the minimum degree is the last
      if (a == "1")
        return false;
      if (b == "1")
        return true;
      const vector<string> as = split(a, '*');
      const vector<string> bs = split(b, '*');
      // the maximum degree is the first
      // Break ties by their lexicographic orders.
      return as.size() == bs.size() ? a < b : as.size() > bs.size();
    });
    auto concat = [&](const string& term) -> string {
      if (term == "1")
        return to_string(terms[term]);
      return to_string(terms[term]) + '*' + term;
    };
    for (const string& key : keys)
      if (terms[key])
        res.push_back(concat(key));
    return res;
  }

  Poly() = default;
  Poly(const string& term, int coef) {
    terms[term] = coef;
  }

 private:
  unordered_map<string, int> terms;

  // e.g. merge("a*b", "a*c") -> "a*a*b*c"
  static string merge(const string& a, const string& b) {
    if (a == "1")
      return b;
    if (b == "1")
      return a;
    string res;
    vector<string> A = split(a, '*');
    vector<string> B = split(b, '*');
    int i = 0;  // A's index
    int j = 0;  // B's index
    while (i < A.size() && j < B.size())
      if (A[i] < B[j])
        res += '*' + A[i++];
      else
        res += '*' + B[j++];
    while (i < A.size())
      res += '*' + A[i++];
    while (j < B.size())
      res += '*' + B[j++];
    return res.substr(1);
  }

  static vector<string> split(const string& token, char c) {
    vector<string> vars;
    istringstream iss(token);
    for (string var; getline(iss, var, c);)
      vars.push_back(var);
    return vars;
  }
};

class Solution {
 public:
  vector<string> basicCalculatorIV(string expression, vector<string>& evalvars,
                                   vector<int>& evalints) {
    vector<string> tokens = getTokens(expression);
    unordered_map<string, int> evalMap;

    for (int i = 0; i < evalvars.size(); ++i)
      evalMap[evalvars[i]] = evalints[i];

    for (string& token : tokens)
      if (const auto it = evalMap.find(token); it != evalMap.cend())
        token = to_string(it->second);

    const vector<string>& postfix = infixToPostfix(tokens);
    return evaluate(postfix).toList();
  }

 private:
  vector<string> getTokens(const string& s) {
    vector<string> tokens;
    int i = 0;
    for (int j = 0; j < s.length(); ++j)
      if (s[j] == ' ') {
        if (i < j)
          tokens.push_back(s.substr(i, j - i));
        i = j + 1;
      } else if (string("()+-*").find(s[j]) != string::npos) {
        if (i < j)
          tokens.push_back(s.substr(i, j - i));
        tokens.push_back(s.substr(j, 1));
        i = j + 1;
      }
    if (i < s.length())
      tokens.push_back(s.substr(i));
    return tokens;
  }

  bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*";
  }

  vector<string> infixToPostfix(const vector<string>& tokens) {
    vector<string> postfix;
    stack<string> ops;

    auto precedes = [](const string& prevOp, const string& currOp) -> bool {
      if (prevOp == "(")
        return false;
      return prevOp == "*" || currOp == "+" || currOp == "-";
    };

    for (const string& token : tokens)
      if (token == "(") {
        ops.push(token);
      } else if (token == ")") {
        while (ops.top() != "(")
          postfix.push_back(ops.top()), ops.pop();
        ops.pop();
      } else if (isOperator(token)) {
        while (!ops.empty() && precedes(ops.top(), token))
          postfix.push_back(ops.top()), ops.pop();
        ops.push(token);
      } else {  // isOperand(token)
        postfix.push_back(token);
      }

    while (!ops.empty())
      postfix.push_back(ops.top()), ops.pop();

    return postfix;
  }

  Poly evaluate(const vector<string>& postfix) {
    vector<Poly> polys;
    for (const string& token : postfix)
      if (isOperator(token)) {
        const Poly b = polys.back();
        polys.pop_back();
        const Poly a = polys.back();
        polys.pop_back();
        if (token == "+")
          polys.push_back(a + b);
        else if (token == "-")
          polys.push_back(a - b);
        else  // token == "*"
          polys.push_back(a * b);
      } else if (token[0] == '-' ||
                 ranges::all_of(token, [](char c) { return isdigit(c); })) {
        polys.push_back(Poly("1", stoi(token)));
      } else {
        polys.push_back(Poly(token, 1));
      }
    return polys[0];
  }
};
