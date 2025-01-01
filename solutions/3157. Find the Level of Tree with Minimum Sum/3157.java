class Solution {
  // Similar to 1161. Maximum Level Sum of a Binary Tree
  public int minimumLevel(TreeNode root) {
    int ans = 0;
    long minLevelSum = Long.MAX_VALUE;
    Queue<TreeNode> q = new LinkedList<>(Arrays.asList(root));

    for (int level = 1; !q.isEmpty(); ++level) {
      long levelSum = 0;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode node = q.poll();
        levelSum += node.val;
        if (node.left != null)
          q.offer(node.left);
        if (node.right != null)
          q.offer(node.right);
      }
      if (levelSum < minLevelSum) {
        minLevelSum = levelSum;
        ans = level;
      }
    }

    return ans;
  }
}
