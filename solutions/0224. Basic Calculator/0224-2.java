class Solution {
  public int calculate(String s) {
    Stack<Integer> nums = new Stack<>(); // stores nums
    Stack<Character> ops = new Stack<>(); // stores operators and parentheses

    for (int i = 0; i < s.length(); ++i) {
      final char c = s.charAt(i);
      if (Character.isDigit(c)) {
        int num = c - '0';
        while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
          num = num * 10 + (s.charAt(i + 1) - '0');
          ++i;
        }
        nums.push(num);
      } else if (c == '(') {
        ops.push(c);
      } else if (c == ')') {
        while (ops.peek() != '(')
          nums.push(calculate(ops.pop(), nums.pop(), nums.pop()));
        ops.pop(); // remove '('
      } else if (c == '+' || c == '-') {
        while (!ops.isEmpty() && ops.peek() != '(')
          nums.push(calculate(ops.pop(), nums.pop(), nums.pop()));
        ops.push(c);
      }
    }

    while (!ops.isEmpty())
      nums.push(calculate(ops.pop(), nums.pop(), nums.pop()));

    return nums.peek();
  }

  private int calculate(char op, int b, int a) {
    return op == '+' ? a + b : a - b;
  }
}
