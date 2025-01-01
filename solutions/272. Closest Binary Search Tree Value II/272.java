class Solution {
  public List<Integer> closestKValues(TreeNode root, double target, int k) {
    Deque<Integer> dq = new ArrayDeque<>();

    inorder(root, dq);

    while (dq.size() > k)
      if (Math.abs(dq.peekFirst() - target) > Math.abs(dq.peekLast() - target))
        dq.pollFirst();
      else
        dq.pollLast();

    return new ArrayList<>(dq);
  }

  private void inorder(TreeNode root, Deque<Integer> dq) {
    if (root == null)
      return;

    inorder(root.left, dq);
    dq.offerLast(root.val);
    inorder(root.right, dq);
  }
}
