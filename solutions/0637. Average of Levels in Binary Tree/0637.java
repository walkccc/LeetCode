class Solution {
  public List<Double> averageOfLevels(TreeNode root) {
    List<Double> ans = new ArrayList<>();
    Queue<TreeNode> q = new ArrayDeque<>(Arrays.asList(root));

    while (!q.isEmpty()) {
      long sum = 0;
      final int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode node = q.poll();
        sum += node.val;
        if (node.left != null)
          q.offer(node.left);
        if (node.right != null)
          q.offer(node.right);
      }
      ans.add(sum / (double) size);
    }

    return ans;
  }
}
