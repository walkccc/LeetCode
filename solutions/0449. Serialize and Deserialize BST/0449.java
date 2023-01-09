public class Codec {
  // Encodes a tree to a single string.
  public String serialize(TreeNode root) {
    if (root == null)
      return "";

    StringBuilder sb = new StringBuilder();

    serialize(root, sb);
    return sb.toString();
  }

  // Decodes your encoded data to tree.
  public TreeNode deserialize(String data) {
    if (data.isEmpty())
      return null;

    final String[] vals = data.split(" ");
    Queue<Integer> q = new ArrayDeque<>();

    for (final String val : vals)
      q.offer(Integer.parseInt(val));

    return deserialize(Integer.MIN_VALUE, Integer.MAX_VALUE, q);
  }

  private void serialize(TreeNode root, StringBuilder sb) {
    if (root == null)
      return;

    sb.append(root.val).append(" ");
    serialize(root.left, sb);
    serialize(root.right, sb);
  }

  private TreeNode deserialize(int min, int max, Queue<Integer> q) {
    if (q.isEmpty())
      return null;

    final int val = q.peek();
    if (val < min || val > max)
      return null;

    q.poll();
    TreeNode root = new TreeNode(val);
    root.left = deserialize(min, val, q);
    root.right = deserialize(val, max, q);
    return root;
  }
}
