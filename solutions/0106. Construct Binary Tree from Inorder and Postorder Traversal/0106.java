class Solution {
  public TreeNode buildTree(int[] inorder, int[] postorder) {
    Map<Integer, Integer> inorderToIndex = new HashMap<>();

    for (int i = 0; i < inorder.length; ++i)
      inorderToIndex.put(inorder[i], i);

    return helper(inorder, 0, inorder.length - 1,
                  postorder, 0, postorder.length - 1,
                  inorderToIndex);
  }

  private TreeNode helper(int[] inorder, int iL, int iR,
                          int[] postorder, int pL, int pR,
                          Map<Integer, Integer> inorderToIndex) {
    if (iL > iR)
      return null;

    final int i = inorderToIndex.get(postorder[pR]);
    TreeNode curr = new TreeNode(postorder[pR]);
    curr.left = helper(inorder, iL, i - 1, postorder, pL, pL + i - iL - 1, inorderToIndex);
    curr.right = helper(inorder, i + 1, iR, postorder, pL + i - iL, pR - 1, inorderToIndex);

    return curr;
  }
}
