class Solution {
  public List<Integer> rightSideView(TreeNode root) {
    if (root == null)
      return new ArrayList<>();

    List<Integer> ans = new ArrayList<>();
    Queue<TreeNode> q = new ArrayDeque<>(Arrays.asList(root));

    while (!q.isEmpty()) {
      final int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode node = q.poll();
        if (i == size - 1)
          ans.add(node.val);
        if (node.left != null)
          q.offer(node.left);
        if (node.right != null)
          q.offer(node.right);
      }
    }

    return ans;
  }
}
