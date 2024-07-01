class Solution {
  public List<Integer> largestValues(TreeNode root) {
    if (root == null)
      return new ArrayList<>();

    List<Integer> ans = new ArrayList<>();
    Queue<TreeNode> q = new ArrayDeque<>(Arrays.asList(root));

    while (!q.isEmpty()) {
      int max = Integer.MIN_VALUE;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode node = q.poll();
        max = Math.max(max, node.val);
        if (node.left != null)
          q.offer(node.left);
        if (node.right != null)
          q.offer(node.right);
      }
      ans.add(max);
    }

    return ans;
  }
}
