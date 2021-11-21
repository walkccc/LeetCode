class Solution {
  public TreeNode buildTree(int[] preorder, int[] inorder) {
    Map<Integer, Integer> inorderToIndex = new HashMap<>();

    for (int i = 0; i < inorder.length; ++i)
      inorderToIndex.put(inorder[i], i);

    return helper(preorder, 0, preorder.length - 1,
                  inorder, 0, inorder.length - 1,
                  inorderToIndex);
  }

  private TreeNode helper(int[] preorder, int pL, int pR,
                          int[] inorder, int iL, int iR,
                          Map<Integer, Integer> inorderToIndex) {
    if (pL > pR)
      return null;

    final int i = inorderToIndex.get(preorder[pL]);
    TreeNode curr = new TreeNode(preorder[pL]);
    curr.left = helper(preorder, pL + 1, pL + i - iL, inorder, iL, i - 1, inorderToIndex);
    curr.right = helper(preorder, pL + i - iL + 1, pR, inorder, i + 1, iR, inorderToIndex);

    return curr;
  }
}
