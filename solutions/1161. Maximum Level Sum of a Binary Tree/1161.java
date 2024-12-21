class Solution {
  public int maxLevelSum(TreeNode root) {
    int ans = 0;
    int maxLevelSum = Integer.MIN_VALUE;
    Queue<TreeNode> q = new LinkedList<>(Arrays.asList(root));

    for (int level = 1; !q.isEmpty(); ++level) {
      int levelSum = 0;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode node = q.poll();
        levelSum += node.val;
        if (node.left != null)
          q.offer(node.left);
        if (node.right != null)
          q.offer(node.right);
      }
      if (levelSum > maxLevelSum) {
        maxLevelSum = levelSum;
        ans = level;
      }
    }

    return ans;
  }
}
