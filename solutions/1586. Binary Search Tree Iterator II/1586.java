class BSTIterator {
  public BSTIterator(TreeNode root) {
    pushLeftsUntilNull(root);
  }

  public boolean hasNext() {
    return !nexts.isEmpty();
  }

  public int next() {
    Pair<TreeNode, Boolean> pair = nexts.pop();
    TreeNode root = pair.getKey();
    boolean fromNext = pair.getValue();
    if (fromNext)
      pushLeftsUntilNull(root.right);
    prevsAndCurr.push(root);
    return root.val;
  }

  public boolean hasPrev() {
    return prevsAndCurr.size() > 1;
  }

  public int prev() {
    nexts.push(new Pair<>(prevsAndCurr.pop(), /*fromNext=*/false));
    return prevsAndCurr.peek().val;
  }

  private void pushLeftsUntilNull(TreeNode root) {
    while (root != null) {
      nexts.push(new Pair<>(root, /*fromNext=*/true));
      root = root.left;
    }
  }

  private Deque<TreeNode> prevsAndCurr = new ArrayDeque<>();
  private Deque<Pair<TreeNode, /*fromNext=*/Boolean>> nexts = new ArrayDeque<>();
}
