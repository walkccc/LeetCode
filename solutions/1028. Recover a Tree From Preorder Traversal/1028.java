class Solution {
  public TreeNode recoverFromPreorder(String S) {
    return recoverFromPreorder(S, 0);
  }

  private int i = 0;

  private TreeNode recoverFromPreorder(final String S, int depth) {
    int nDashes = 0;
    while (i + nDashes < S.length() && S.charAt(i + nDashes) == '-')
      ++nDashes;
    if (nDashes != depth)
      return null;

    i += depth;
    final int start = i;
    while (i < S.length() && Character.isDigit(S.charAt(i)))
      ++i;

    final int val = Integer.parseInt(S.substring(start, i));
    TreeNode root = new TreeNode(val);

    root.left = recoverFromPreorder(S, depth + 1);
    root.right = recoverFromPreorder(S, depth + 1);

    return root;
  }
}
