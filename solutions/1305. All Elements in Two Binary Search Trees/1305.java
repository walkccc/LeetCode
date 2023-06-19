class BSTIterator {
  public BSTIterator(TreeNode root) {
    pushLeftsUntilNull(root);
  }

  public int peek() {
    return stack.peek().val;
  }

  public void next() {
    pushLeftsUntilNull(stack.pop().right);
  }

  public boolean hasNext() {
    return !stack.isEmpty();
  }

  private Deque<TreeNode> stack = new ArrayDeque<>();

  private void pushLeftsUntilNull(TreeNode node) {
    while (node != null) {
      stack.push(node);
      node = node.left;
    }
  }
}

class Solution {
  public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
    List<Integer> ans = new ArrayList<>();
    BSTIterator bstIterator1 = new BSTIterator(root1);
    BSTIterator bstIterator2 = new BSTIterator(root2);

    while (bstIterator1.hasNext() && bstIterator2.hasNext())
      if (bstIterator1.peek() < bstIterator2.peek()) {
        ans.add(bstIterator1.peek());
        bstIterator1.next();
      } else {
        ans.add(bstIterator2.peek());
        bstIterator2.next();
      }

    while (bstIterator1.hasNext()) {
      ans.add(bstIterator1.peek());
      bstIterator1.next();
    }

    while (bstIterator2.hasNext()) {
      ans.add(bstIterator2.peek());
      bstIterator2.next();
    }

    return ans;
  }
}
