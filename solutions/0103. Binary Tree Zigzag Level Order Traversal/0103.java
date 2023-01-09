class Solution {
  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    if (root == null)
      return new ArrayList<>();

    List<List<Integer>> ans = new ArrayList<>();
    Deque<TreeNode> q = new ArrayDeque<>(Arrays.asList(root));
    boolean isLeftToRight = true;

    while (!q.isEmpty()) {
      List<Integer> currLevel = new ArrayList<>();
      for (int sz = q.size(); sz > 0; --sz)
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
