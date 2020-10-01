class Solution {
  public List<List<Integer>> verticalOrder(TreeNode root) {
    if (root == null)
      return new ArrayList<>();

    List<List<Integer>> ans = new ArrayList<>();
    Queue<Pair<TreeNode, Integer>> q = new LinkedList<>(); // {TreeNode, colIndex}
    int[] range = new int[2];

    getRange(root, range, 0); // get the leftmost and rightmost column index
    q.offer(new Pair<>(root, -range[0]));

    for (int i = range[0]; i <= range[1]; ++i)
      ans.add(new ArrayList<>());

    while (!q.isEmpty()) {
      final TreeNode node = q.peek().getKey();
      final int colIndex = q.poll().getValue();
      ans.get(colIndex).add(node.val);
      if (node.left != null)
        q.offer(new Pair<>(node.left, colIndex - 1));
      if (node.right != null)
        q.offer(new Pair<>(node.right, colIndex + 1));
    }

    return ans;
  }

  private void getRange(TreeNode root, int[] range, int col) {
    if (root == null)
      return;

    range[0] = Math.min(range[0], col);
    range[1] = Math.max(range[1], col);

    getRange(root.left, range, col - 1);
    getRange(root.right, range, col + 1);
  }
}