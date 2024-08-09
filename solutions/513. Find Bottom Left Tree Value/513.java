class Solution {
  public int findBottomLeftValue(TreeNode root) {
    Queue<TreeNode> q = new ArrayDeque<>(Arrays.asList(root));
    TreeNode node = null;

    while (!q.isEmpty()) {
      node = q.poll();
      if (node.right != null)
        q.offer(node.right);
      if (node.left != null)
        q.offer(node.left);
    }

    return node.val;
  }
}
