class Solution {
  public int deepestLeavesSum(TreeNode root) {
    int ans = 0;
    Queue<TreeNode> q = new ArrayDeque<>(List.of(root));

    while (!q.isEmpty()) {
      ans = 0;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode node = q.poll();
        ans += node.val;
        if (node.left != null)
          q.offer(node.left);
        if (node.right != null)
          q.offer(node.right);
      }
    }

    return ans;
  }
}
