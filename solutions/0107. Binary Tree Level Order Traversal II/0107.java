class Solution {
  public List<List<Integer>> levelOrderBottom(TreeNode root) {
    if (root == null)
      return new ArrayList<>();

    List<List<Integer>> ans = new ArrayList<>();
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    while (!q.isEmpty()) {
      List<Integer> currLevel = new ArrayList<>();
      for (int i = q.size(); i > 0; --i) {
        root = q.poll();
        currLevel.add(root.val);
        if (root.left != null)
          q.offer(root.left);
        if (root.right != null)
          q.offer(root.right);
      }
      ans.add(currLevel);
    }

    Collections.reverse(ans);
    return ans;
  }
}