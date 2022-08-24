class Solution {
 public:
  string solveEquation(string equation) {
    const string lhsEquation = equation.substr(0, equation.find('='));
    const string rhsEquation = equation.substr(equation.find('=') + 1);
    const auto& [lhsCoefficient, lhsConstant] = calculate(lhsEquation);
    const auto& [rhsCoefficient, rhsConstant] = calculate(rhsEquation);
    const int coefficient = lhsCoefficient - rhsCoefficient;
    const int constant = rhsConstant - lhsConstant;

    if (coefficient == 0 && constant == 0)
      return "Infinite solutions";
    if (coefficient == 0 && constant != 0)
      return "No solution";
    return "x=" + to_string(constant / coefficient);
  }

 private:
  pair<int, int> calculate(const string& s) {
    int coefficient = 0;
    int constant = 0;
    int num = 0;
    int sign = 1;

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      if (isdigit(c))
        num = num * 10 + (c - '0');
      else if (c == '+' || c == '-') {
        constant += sign * num;
        sign = c == '+' ? 1 : -1;
        num = 0;
      } else {
        if (i > 0 && num == 0 && s[i - 1] == '0')
          continue;
        coefficient += num == 0 ? sign : sign * num;
        num = 0;
      }
    }

    return {coefficient, constant + sign * num};
  }
};
