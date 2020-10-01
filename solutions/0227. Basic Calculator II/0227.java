class Solution {
  public int calculate(String s) {
    int ans = 0;
    int num = 0;
    char sign = '+';
    Stack<Integer> stack = new Stack<>();

    for (final char c : (s + "+").toCharArray())
      if (Character.isDigit(c)) {
        num = num * 10 + (c - '0');
      } else if (isSign(c)) {
        switch (sign) {
          case '+':
            stack.push(num);
            break;
          case '-':
            stack.push(-num);
            break;
          case '*':
            stack.push(stack.pop() * num);
            break;
          default:
            stack.push(stack.pop() / num);
            break;
        }
        num = 0;
        sign = c;
      }

    while (!stack.isEmpty())
      ans += stack.pop();

    return ans;
  }

  private boolean isSign(final char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
  }
}