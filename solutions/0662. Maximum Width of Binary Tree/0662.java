class Solution {
  public int widthOfBinaryTree(TreeNode root) {
    if (root == null)
      return 0;

    int ans = 0;
    Deque<Pair<TreeNode, Integer>> q = new ArrayDeque<>(); // {node, index}
    q.offer(new Pair<>(root, 1));

    while (!q.isEmpty()) {
      final int offset = q.peekFirst().getValue() * 2;
      ans = Math.max(ans, q.peekLast().getValue() - q.peekFirst().getValue() + 1);
      for (int sz = q.size(); sz > 0; --sz) {
        final TreeNode node = q.peekFirst().getKey();
        final int index = q.pollFirst().getValue();
        if (node.left != null)
          q.offer(new Pair<>(node.left, index * 2 - offset));
        if (node.right != null)
          q.offer(new Pair<>(node.right, index * 2 + 1 - offset));
      }
    }

    return ans;
  }
}
