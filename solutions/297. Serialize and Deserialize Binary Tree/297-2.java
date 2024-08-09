public class Codec {
  // Encodes a tree to a single string.
  public String serialize(TreeNode root) {
    StringBuilder sb = new StringBuilder();
    preorder(root, sb);
    return sb.toString();
  }

  // Decodes your encoded data to tree.
  public TreeNode deserialize(String data) {
    final String[] vals = data.split(" ");
    Queue<String> q = new ArrayDeque<>(Arrays.asList(vals));
    return preorder(q);
  }

  private void preorder(TreeNode root, StringBuilder sb) {
    if (root == null) {
      sb.append("n ");
      return;
    }

    sb.append(root.val).append(" ");
    preorder(root.left, sb);
    preorder(root.right, sb);
  }

  private TreeNode preorder(Queue<String> q) {
    final String s = q.poll();
    if (s.equals("n"))
      return null;

    TreeNode root = new TreeNode(Integer.parseInt(s));
    root.left = preorder(q);
    root.right = preorder(q);
    return root;
  }
}
