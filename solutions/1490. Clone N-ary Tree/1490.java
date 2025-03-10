class Solution {
  public Node cloneTree(Node root) {
    if (root == null)
      return null;
    if (map.containsKey(root))
      return map.get(root);

    Node newNode = new Node(root.val);
    map.put(root, newNode);

    for (Node child : root.children)
      newNode.children.add(cloneTree(child));

    return newNode;
  }

  private Map<Node, Node> map = new HashMap<>();
}
