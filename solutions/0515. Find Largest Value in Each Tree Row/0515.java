class Solution {
  public List<Integer> largestValues(TreeNode root) {
    if (root == null)
      return new ArrayList<>();

    List<Integer> ans = new ArrayList<>();
    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(root);

    while (!queue.isEmpty()) {
      int max = Integer.MIN_VALUE;
      for (int i = queue.size(); i > 0; --i) {
        root = queue.poll();
        max = Math.max(max, root.val);
        if (root.left != null)
          queue.add(root.left);
        if (root.right != null)
          queue.add(root.right);
      }
      ans.add(max);
    }

    return ans;
  }
}