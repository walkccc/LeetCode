class Solution {
  public TreeNode buildTree(int[] preorder, int[] inorder) {
    Map<Integer, Integer> inToIndex = new HashMap<>();

    for (int i = 0; i < inorder.length; ++i)
      inToIndex.put(inorder[i], i);

    return build(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1, inToIndex);
  }

  private TreeNode build(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart,
                         int inEnd, Map<Integer, Integer> inToIndex) {
    if (preStart > preEnd)
      return null;

    final int rootVal = preorder[preStart];
    final int rootInIndex = inToIndex.get(rootVal);
    final int leftSize = rootInIndex - inStart;

    TreeNode root = new TreeNode(rootVal);
    root.left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart,
                      rootInIndex - 1, inToIndex);
    root.right = build(preorder, preStart + leftSize + 1, preEnd, inorder, rootInIndex + 1, inEnd,
                       inToIndex);

    return root;
  }
}
