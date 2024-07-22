class Solution {
  public Node findRoot(List<Node> tree) {
    int sum = 0;

    for (Node node : tree) {
      sum ^= node.val;
      for (Node child : node.children)
        sum ^= child.val;
    }

    for (Node node : tree)
      if (node.val == sum)
        return node;

    throw new IllegalArgumentException();
  }
}
