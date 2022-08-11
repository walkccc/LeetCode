class Solution {
  public TreeNode bstFromPreorder(int[] preorder) {
    TreeNode root = new TreeNode(preorder[0]);
    Deque<TreeNode> stack = new ArrayDeque<>(Arrays.asList(root));

    for (int i = 1; i < preorder.length; ++i) {
      TreeNode parent = stack.peek();
      TreeNode child = new TreeNode(preorder[i]);
      // adjust parent
      while (!stack.isEmpty() && stack.peek().val < child.val)
        parent = stack.pop();
      // create parent-child link according to BST property
      if (parent.val > child.val)
        parent.left = child;
      else
        parent.right = child;
      stack.push(child);
    }

    return root;
  }
}
