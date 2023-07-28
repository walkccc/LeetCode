class Solution {
  public int minLength(String s) {
    Deque<Character> stack = new ArrayDeque<>();

    for (final char c : s.toCharArray())
      if (c == 'B' && match(stack, 'A'))
        stack.pop();
      else if (c == 'D' && match(stack, 'C'))
        stack.pop();
      else
        stack.push(c);

    return stack.size();
  }

  private boolean match(Deque<Character> stack, char c) {
    return !stack.isEmpty() && stack.peek() == c;
  }
}
