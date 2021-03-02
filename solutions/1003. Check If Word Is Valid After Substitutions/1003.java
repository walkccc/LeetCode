class Solution {
  public boolean isValid(String S) {
    Stack<Character> stack = new Stack<>();

    for (char c : S.toCharArray())
      if (c == 'c') {
        if (stack.size() < 2)
          return false;
        if (stack.peek() != 'b')
          return false;
        stack.pop();
        if (stack.peek() != 'a')
          return false;
        stack.pop();
      } else
        stack.push(c);

    return stack.isEmpty();
  }
}
