class Solution {
  public String solveEquation(String equation) {
    String[] equations = equation.split("=");
    int[] lhs = calculate(equations[0]);
    int[] rhs = calculate(equations[1]);
    int coefficient = lhs[0] - rhs[0];
    int constant = rhs[1] - lhs[1];

    if (coefficient == 0 && constant == 0)
      return "Infinite solutions";
    if (coefficient == 0 && constant != 0)
      return "No solution";
    return "x=" + constant / coefficient;
  }

  private int[] calculate(final String s) {
    int coefficient = 0;
    int constant = 0;
    int num = 0;
    int sign = 1;

    for (int i = 0; i < s.length(); ++i) {
      char c = s.charAt(i);
      if (Character.isDigit(c))
        num = num * 10 + (c - '0');
      else if (c == '+' || c == '-') {
        constant += sign * num;
        sign = c == '+' ? 1 : -1;
        num = 0;
      } else {
        if (i > 0 && num == 0 && s.charAt(i - 1) == '0')
          continue;
        coefficient += num == 0 ? sign : sign * num;
        num = 0;
      }
    }

    return new int[] {coefficient, constant + sign * num};
  }
}
