class Solution {
  public TreeNode str2tree(String s) {
    if (s.isEmpty())
      return null;
    return helper(s);
  }

  private int i = 0;

  private TreeNode helper(final String s) {
    final int start = i; // start index of val
    if (s.charAt(i) == '-')
      ++i;
    while (i < s.length() && Character.isDigit(s.charAt(i)))
      ++i;

    final int val = Integer.parseInt(s.substring(start, i));
    TreeNode root = new TreeNode(val);

    // left child
    if (i < s.length() && s.charAt(i) == '(') {
      ++i; // '('
      root.left = helper(s);
      ++i; // ')'
    }

    // right child
    if (i < s.length() && s.charAt(i) == '(') {
      ++i; // '('
      root.right = helper(s);
      ++i; // ')'
    }

    return root;
  }
}
