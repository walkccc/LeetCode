class Solution {
  public List<List<Integer>> levelOrder(TreeNode root) {
    if (root == null)
      return new ArrayList<>();

    List<List<Integer>> ans = new ArrayList<>();
    Queue<TreeNode> q = new LinkedList<>(Arrays.asList(root));

    while (!q.isEmpty()) {
      List<Integer> currLevel = new ArrayList<>();
      for (int size = q.size(); size > 0; --size) {
        TreeNode node = q.poll();
        currLevel.add(node.val);
        if (node.left != null)
          q.offer(node.left);
        if (node.right != null)
          q.offer(node.right);
      }
      ans.add(currLevel);
    }

    return ans;
  }
}
