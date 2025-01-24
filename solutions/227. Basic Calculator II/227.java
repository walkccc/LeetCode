class Solution {
  public int calculate(String s) {
    Deque<Integer> nums = new ArrayDeque<>();
    Deque<Character> ops = new ArrayDeque<>();

    for (int i = 0; i < s.length(); ++i) {
      final char c = s.charAt(i);
      if (Character.isDigit(c)) {
        int num = c - '0';
        while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
          num = num * 10 + (s.charAt(i + 1) - '0');
          ++i;
        }
        nums.push(num);
      } else if (c == '+' || c == '-' || c == '*' || c == '/') {
        while (!ops.isEmpty() && compare(ops.peek(), c))
          nums.push(calculate(ops.pop(), nums.pop(), nums.pop()));
        ops.push(c);
      }
    }

    while (!ops.isEmpty())
      nums.push(calculate(ops.pop(), nums.pop(), nums.pop()));

    return nums.peek();
  }

  private int calculate(char op, int b, int a) {
    switch (op) {
      case '+':
        return a + b;
      case '-':
        return a - b;
      case '*':
        return a * b;
      case '/':
        return a / b;
    }
    throw new IllegalArgumentException();
  }

  // Returns true if priority(op1) >= priority(op2).
  private boolean compare(char op1, char op2) {
    return op1 == '*' || op1 == '/' || op2 == '+' || op2 == '-';
  }
}
