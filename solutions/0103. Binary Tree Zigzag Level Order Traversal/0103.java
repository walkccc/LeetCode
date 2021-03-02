class Solution {
  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    if (root == null)
      return new ArrayList<>();

    List<List<Integer>> ans = new ArrayList<>();
    Deque<TreeNode> q = new ArrayDeque<>();
    q.addLast(root);
    boolean isLeftToRight = true;

    while (!q.isEmpty()) {
      List<Integer> currLevel = new ArrayList<>();
      for (int size = q.size(); size > 0; --size)
        if (isLeftToRight) {
          TreeNode node = q.pollFirst();
          currLevel.add(node.val);
          if (node.left != null)
            q.addLast(node.left);
          if (node.right != null)
            q.addLast(node.right);
        } else {
          TreeNode node = q.pollLast();
          currLevel.add(node.val);
          if (node.right != null)
            q.addFirst(node.right);
          if (node.left != null)
            q.addFirst(node.left);
        }
      ans.add(currLevel);
      isLeftToRight = !isLeftToRight;
    }

    return ans;
  }
}
