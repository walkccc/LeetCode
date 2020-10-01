class Solution {
  public List<Integer> rightSideView(TreeNode root) {
    if (root == null)
      return new ArrayList<>();

    List<Integer> ans = new ArrayList<>();
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    while (!q.isEmpty()) {
      final int size = q.size();
      for (int i = 0; i < size; ++i) {
        root = q.poll();
        if (i == size - 1)
          ans.add(root.val);
        if (root.left != null)
          q.offer(root.left);
        if (root.right != null)
          q.offer(root.right);
      }
    }

    return ans;
  }
}