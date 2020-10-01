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
      for (int i = q.size(); i > 0; --i)
        if (isLeftToRight) {
          root = q.pollFirst();
          currLevel.add(root.val);
          if (root.left != null)
            q.addLast(root.left);
          if (root.right != null)
            q.addLast(root.right);
        } else {
          root = q.pollLast();
          currLevel.add(root.val);
          if (root.right != null)
            q.addFirst(root.right);
          if (root.left != null)
            q.addFirst(root.left);
        }
      ans.add(currLevel);
      isLeftToRight = !isLeftToRight;
    }

    return ans;
  }
}