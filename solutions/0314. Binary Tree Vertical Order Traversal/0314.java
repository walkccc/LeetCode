class Solution {
  public List<List<Integer>> verticalOrder(TreeNode root) {
    if (root == null)
      return new ArrayList<>();

    List<List<Integer>> ans = new ArrayList<>();
    Queue<Pair<TreeNode, Integer>> q = new ArrayDeque<>(); // (TreeNode, x)
    int[] range = new int[2];
    getRange(root, range, 0); // get the leftmost and rightmost x index

    for (int i = range[0]; i <= range[1]; ++i)
      ans.add(new ArrayList<>());

    q.offer(new Pair<>(root, -range[0]));

    while (!q.isEmpty()) {
      final TreeNode node = q.peek().getKey();
      final int x = q.poll().getValue();
      ans.get(x).add(node.val);
      if (node.left != null)
        q.offer(new Pair<>(node.left, x - 1));
      if (node.right != null)
        q.offer(new Pair<>(node.right, x + 1));
    }

    return ans;
  }

  private void getRange(TreeNode root, int[] range, int x) {
    if (root == null)
      return;

    range[0] = Math.min(range[0], x);
    range[1] = Math.max(range[1], x);

    getRange(root.left, range, x - 1);
    getRange(root.right, range, x + 1);
  }
}
