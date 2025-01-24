class Solution {
  public int minDepth(TreeNode root) {
    if (root == null)
      return 0;

    Queue<TreeNode> q = new ArrayDeque<>(List.of(root));

    for (int step = 1; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode node = q.poll();
        if (node.left == null && node.right == null)
          return step;
        if (node.left != null)
          q.offer(node.left);
        if (node.right != null)
          q.offer(node.right);
      }

    throw new IllegalArgumentException();
  }
}
