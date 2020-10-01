public class Codec {
  // Encodes a tree to a single string.
  public String serialize(TreeNode root) {
    if (root == null)
      return "";

    StringBuilder sb = new StringBuilder();
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    while (!q.isEmpty()) {
      root = q.poll();
      if (root == null) {
        sb.append("n").append(" ");
        continue;
      }
      sb.append(root.val).append(" ");
      q.offer(root.left);
      q.offer(root.right);
    }

    return sb.toString();
  }

  // Decodes your encoded data to tree.
  public TreeNode deserialize(String data) {
    if (data.equals(""))
      return null;

    final String[] vals = data.split(" ");
    TreeNode root = new TreeNode(Integer.parseInt(vals[0]));
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    for (int i = 1; i < vals.length; ++i) {
      TreeNode parent = q.poll();
      if (!vals[i].equals("n")) {
        TreeNode left = new TreeNode(Integer.parseInt(vals[i]));
        parent.left = left;
        q.offer(left);
      }
      if (!vals[++i].equals("n")) {
        TreeNode right = new TreeNode(Integer.parseInt(vals[i]));
        parent.right = right;
        q.offer(right);
      }
    }

    return root;
  }
}