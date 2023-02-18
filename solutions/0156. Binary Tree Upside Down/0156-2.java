class Solution {
  public TreeNode upsideDownBinaryTree(TreeNode root) {
    TreeNode prevRoot = null;
    TreeNode prevRightChild = null;

    while (root != null) {
      TreeNode nextRoot = root.left; // Cache next root
      root.left = prevRightChild;
      prevRightChild = root.right;
      root.right = prevRoot;
      prevRoot = root; // Record previous root
      root = nextRoot; // Update root
    }

    return prevRoot;
  }
}
