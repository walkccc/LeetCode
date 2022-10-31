class Solution {
  public NestedInteger deserialize(String s) {
    if (s.charAt(0) != '[')
      return new NestedInteger(Integer.parseInt(s));

    Deque<NestedInteger> stack = new ArrayDeque<>();
    int start = 1;

    for (int i = 0; i < s.length(); ++i)
      switch (s.charAt(i)) {
        case '[':
          stack.push(new NestedInteger());
          start = i + 1;
          break;
        case ',':
          if (i > start) {
            final int num = Integer.parseInt(s.substring(start, i));
            stack.peek().add(new NestedInteger(num));
          }
          start = i + 1;
          break;
        case ']':
          NestedInteger popped = stack.pop();
          if (i > start) {
            final int num = Integer.parseInt(s.substring(start, i));
            popped.add(new NestedInteger(num));
          }
          if (!stack.isEmpty())
            stack.peek().add(popped);
          else
            return popped;
          start = i + 1;
          break;
      }

    throw new IllegalArgumentException();
  }
}
