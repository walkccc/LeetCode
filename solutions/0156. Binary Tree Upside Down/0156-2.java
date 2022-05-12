class Solution {
  public TreeNode upsideDownBinaryTree(TreeNode root) {
    TreeNode prevRoot = null;
    TreeNode prevRightChild = null;

    while (root != null) {
      TreeNode nextRoot = root.left; // cache next root
      root.left = prevRightChild;
      prevRightChild = root.right;
      root.right = prevRoot;
      prevRoot = root; // record previous root
      root = nextRoot; // update root
    }

    return prevRoot;
  }
}
