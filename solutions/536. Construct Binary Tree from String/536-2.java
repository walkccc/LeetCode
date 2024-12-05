class Solution {
  public TreeNode str2tree(String s) {
    if (s.isEmpty())
      return null;

    Deque<TreeNode> stack = new ArrayDeque<>();

    for (int l = 0, r = 0; r < s.length(); l = ++r)
      if (s.charAt(r) == ')') {
        stack.pop();
      } else if (Character.isDigit(s.charAt(r)) || s.charAt(r) == '-') {
        while (r + 1 < s.length() && Character.isDigit(s.charAt(r + 1)))
          ++r;
        final int val = Integer.parseInt(s.substring(l, r + 1));
        TreeNode node = new TreeNode(val);
        if (!stack.isEmpty()) {
          TreeNode parent = stack.peek();
          if (parent.left != null)
            parent.right = node;
          else
            parent.left = node;
        }
        stack.push(node);
      }

    return stack.peek();
  }
}
