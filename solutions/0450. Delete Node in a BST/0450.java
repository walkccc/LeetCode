class Solution {
  public TreeNode deleteNode(TreeNode root, int key) {
    if (root == null)
      return null;
    if (root.val > key)
      root.left = deleteNode(root.left, key);
    else if (root.val < key)
      root.right = deleteNode(root.right, key);
    else { // root.val == key
      if (root.left == null)
        return root.right;
      if (root.right == null)
        return root.left;

      TreeNode cache = root;
      // update root to be the minimum value of root's right subtree
      root = getMin(root.right);
      root.right = deleteMin(cache.right);
      root.left = cache.left;
    }

    return root;
  }

  private TreeNode getMin(TreeNode root) {
    if (root.left == null)
      return root;
    return getMin(root.left);
  }

  private TreeNode deleteMin(TreeNode root) {
    if (root.left == null) // delete root itself
      return root.right;
    root.left = deleteMin(root.left);
    return root;
  }
}
