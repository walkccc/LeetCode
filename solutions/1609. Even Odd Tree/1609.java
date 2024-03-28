class Solution {
  public boolean isEvenOddTree(TreeNode root) {
    Queue<TreeNode> q = new LinkedList<>(Arrays.asList(root));
    boolean isEven = true;

    for (; !q.isEmpty(); isEven = !isEven) {
      int prevVal = isEven ? Integer.MIN_VALUE : Integer.MAX_VALUE;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode node = q.poll();
        if (isEven && (node.val % 2 == 0 || node.val <= prevVal))
          return false; // invalid case on even level
        if (!isEven && (node.val % 2 == 1 || node.val >= prevVal))
          return false; // invalid case on odd level
        prevVal = node.val;
        if (node.left != null)
          q.offer(node.left);
        if (node.right != null)
          q.offer(node.right);
      }
    }

    return true;
  }
}
