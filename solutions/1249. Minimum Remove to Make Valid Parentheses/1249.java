class Solution {
  public String minRemoveToMakeValid(String s) {
    Deque<Integer> stack = new ArrayDeque<>(); // Unpaired '(' indices
    StringBuilder sb = new StringBuilder(s);

    for (int i = 0; i < s.length(); ++i)
      if (sb.charAt(i) == '(') {
        stack.push(i); // Record unpaired '(' index
      } else if (sb.charAt(i) == ')') {
        if (stack.isEmpty())
          sb.setCharAt(i, '#'); // Mark unpaired ')' as '#'
        else
          stack.pop(); // Find a pair!
      }

    // Mark unpaired '(' as '#'
    while (!stack.isEmpty())
      sb.setCharAt(stack.pop(), '#');

    return sb.toString().replaceAll("#", "");
  }
}
