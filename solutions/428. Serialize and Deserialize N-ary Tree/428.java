class Codec {
  // Encodes a tree to a single string.
  public String serialize(Node root) {
    if (root == null)
      return "";

    StringBuilder sb = new StringBuilder().append(root.val).append(",");
    Queue<Node> q = new ArrayDeque<>(Arrays.asList(root));

    while (!q.isEmpty())
      for (int sz = q.size(); sz > 0; --sz) {
        Node node = q.poll();
        if (node.children.isEmpty()) {
          sb.append("n");
        } else {
          for (Node child : node.children) {
            q.offer(child);
            sb.append(child.val).append("#");
          }
        }
        sb.append(",");
      }

    return sb.toString();
  }

  // Decodes your encoded data to tree.
  public Node deserialize(String data) {
    if (data.equals(""))
      return null;

    final String[] vals = data.split(",");
    Node root = new Node(Integer.parseInt(vals[0]));
    Queue<Node> q = new ArrayDeque<>(Arrays.asList(root));

    for (int i = 1; i < vals.length; ++i) {
      Node parent = q.poll();
      final String[] kids = vals[i].split("#");
      List<Node> children = new ArrayList<>();
      for (final String kid : kids) {
        if (kid.equals("n"))
          continue;
        Node child = new Node(Integer.parseInt(kid));
        children.add(child);
        q.offer(child);
      }
      parent.children = children;
    }

    return root;
  }
}
