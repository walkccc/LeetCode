class Solution {
  public void recoverTree(TreeNode root) {
    TreeNode pred = null;
    TreeNode x = null; // 1st wrong node
    TreeNode y = null; // 2nd wrong node

    while (root != null) {
      if (root.left == null) {
        // start the main logic
        if (pred != null && root.val < pred.val) {
          y = root;
          if (x == null)
            x = pred;
        }
        pred = root;
        // end of the main logic
        root = root.right;
      } else {
        TreeNode morrisPred = findPredecessor(root);
        if (morrisPred.right == null) {
          morrisPred.right = root; // connect it!
          root = root.left;
        } else { // already connected before
          // start the main logic
          if (pred != null && root.val < pred.val) {
            y = root;
            if (x == null)
              x = pred;
          }
          pred = root;
          // end of the main logic
          morrisPred.right = null; // break the connection
          root = root.right;
        }
      }
    }

    swap(x, y);
  }

  private TreeNode findPredecessor(TreeNode root) {
    TreeNode pred = root.left;
    while (pred.right != null && pred.right != root)
      pred = pred.right;
    return pred;
  }

  private void swap(TreeNode x, TreeNode y) {
    final int temp = x.val;
    x.val = y.val;
    y.val = temp;
  }
}
