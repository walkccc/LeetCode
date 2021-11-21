class Solution {
  public NodeCopy copyRandomBinaryTree(Node root) {
    if (root == null)
      return null;
    if (map.containsKey(root))
      return map.get(root);

    NodeCopy newNode = new NodeCopy(root.val);
    map.put(root, newNode);

    newNode.left = copyRandomBinaryTree(root.left);
    newNode.right = copyRandomBinaryTree(root.right);
    newNode.random = copyRandomBinaryTree(root.random);

    return newNode;
  }

  private Map<Node, NodeCopy> map = new HashMap<>();
}
