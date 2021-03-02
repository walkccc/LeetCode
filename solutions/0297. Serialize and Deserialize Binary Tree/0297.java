public class Codec {
  // Encodes a tree to a single string.
  public String serialize(TreeNode root) {
    if (root == null)
      return "";

    StringBuilder sb = new StringBuilder();
    Queue<TreeNode> q = new LinkedList<>(Arrays.asList(root));

    while (!q.isEmpty()) {
      TreeNode node = q.poll();
      if (node == null) {
        sb.append("n").append(" ");
      } else {
        sb.append(node.val).append(" ");
        q.offer(node.left);
        q.offer(node.right);
      }
    }

    return sb.toString();
  }

  // Decodes your encoded data to tree.
  public TreeNode deserialize(String data) {
    if (data.equals(""))
      return null;

    final String[] vals = data.split(" ");
    TreeNode root = new TreeNode(Integer.parseInt(vals[0]));
    Queue<TreeNode> q = new LinkedList<>(Arrays.asList(root));

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
