class Solution {
  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    if (root == null)
      return new ArrayList<>();

    List<List<Integer>> ans = new ArrayList<>();
    Deque<TreeNode> q = new ArrayDeque<>(Arrays.asList(root));
    boolean isLeftToRight = true;

    while (!q.isEmpty()) {
      List<Integer> currLevel = new ArrayList<>();
      for (int size = q.size(); size > 0; --size) {
        TreeNode node = q.poll();
        if (isLeftToRight)
          currLevel.add(node.val);
        else
          currLevel.add(0, node.val);
        if (node.left != null)
          q.offer(node.left);
        if (node.right != null)
          q.offer(node.right);
      }
      ans.add(currLevel);
      isLeftToRight = !isLeftToRight;
    }

    return ans;
  }
}
