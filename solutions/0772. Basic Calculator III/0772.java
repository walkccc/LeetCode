class Solution {
  public int calculate(String s) {
    Deque<Integer> nums = new ArrayDeque<>();
    Deque<Character> ops = new ArrayDeque<>();
    boolean hasPrevNum = false;

    for (int i = 0; i < s.length(); ++i) {
      final char c = s.charAt(i);
      if (Character.isDigit(c)) {
        int num = c - '0';
        while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1)))
          num = num * 10 + (s.charAt(i++ + 1) - '0');
        nums.push(num);
        hasPrevNum = true;
      } else if (c == '(') {
        ops.push('(');
        hasPrevNum = false;
      } else if (c == ')') {
        while (ops.peek() != '(')
          calc(nums, ops);
        ops.pop(); // pop '('
      } else if (c == '+' || c == '-' || c == '*' || c == '/') {
        if (!hasPrevNum)
          nums.push(0);
        while (!ops.isEmpty() && precedes(ops.peek(), c))
          calc(nums, ops);
        ops.push(c);
      }
    }

    while (!ops.isEmpty())
      calc(nums, ops);

    return nums.peek();
  }

  private void calc(Deque<Integer> nums, Deque<Character> ops) {
    final int b = nums.pop();
    final int a = nums.pop();
    final char op = ops.pop();
    if (op == '+')
      nums.push(a + b);
    else if (op == '-')
      nums.push(a - b);
    else if (op == '*')
      nums.push(a * b);
    else // op == '/'
      nums.push(a / b);
  }

  // return true if prevOp is a operator and
  // priority(prevOp) >= priority(currOp)
  private boolean precedes(char prevOp, char currOp) {
    if (prevOp == '(')
      return false;
    return prevOp == '*' || prevOp == '/' || currOp == '+' || currOp == '-';
  }
}
