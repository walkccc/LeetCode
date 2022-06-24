class Solution {
  public String minRemoveToMakeValid(String s) {
    Deque<Integer> stack = new ArrayDeque<>(); // unpaired '(' indices
    StringBuilder sb = new StringBuilder(s);

    for (int i = 0; i < s.length(); ++i)
      if (sb.charAt(i) == '(') {
        stack.push(i); // record unpaired '(' index
      } else if (sb.charAt(i) == ')') {
        if (stack.isEmpty())
          sb.setCharAt(i, '#'); // mark unpaired ')' as '#'
        else
          stack.pop(); // find a pair!
      }

    // mark unpaired '(' as '#'
    while (!stack.isEmpty())
      sb.setCharAt(stack.pop(), '#');

    return sb.toString().replaceAll("#", "");
  }
}
