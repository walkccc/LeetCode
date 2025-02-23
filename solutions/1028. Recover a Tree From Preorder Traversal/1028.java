class Solution {
  public TreeNode recoverFromPreorder(String traversal) {
    return recoverFromPreorder(traversal, 0);
  }

  private int i = 0;

  private TreeNode recoverFromPreorder(final String traversal, int depth) {
    int nDashes = 0;
    while (i + nDashes < traversal.length() && traversal.charAt(i + nDashes) == '-')
      ++nDashes;
    if (nDashes != depth)
      return null;

    i += depth;
    final int start = i;
    while (i < traversal.length() && Character.isDigit(traversal.charAt(i)))
      ++i;

    return new TreeNode(Integer.valueOf(traversal.substring(start, i)),
                        recoverFromPreorder(traversal, depth + 1),
                        recoverFromPreorder(traversal, depth + 1));
  }
}
