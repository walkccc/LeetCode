class Solution {
  public int countGreatEnoughNodes(TreeNode root, int k) {
    dfs(root, k);
    return ans;
  }

  private int ans = 0;

  private Queue<Integer> dfs(TreeNode root, int k) {
    if (root == null)
      return new PriorityQueue<>(Collections.reverseOrder());

    Queue<Integer> kSmallest = dfs(root.left, k);
    Queue<Integer> kSmallestRight = dfs(root.right, k);
    kSmallest.addAll(kSmallestRight);

    while (kSmallest.size() > k)
      kSmallest.poll();
    if (kSmallest.size() == k && root.val > kSmallest.peek())
      ++ans;

    kSmallest.offer(root.val);
    return kSmallest;
  }
}
