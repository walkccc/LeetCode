class Solution {
  public int deepestLeavesSum(TreeNode root) {
    int ans = 0;
    Queue<TreeNode> q = new LinkedList<>(Arrays.asList(root));

    while (!q.isEmpty()) {
      ans = 0;
      for (int size = q.size(); size > 0; --size) {
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
