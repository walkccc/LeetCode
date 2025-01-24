class Codec {
  // Encodes an n-ary tree to a binary tree.
  public TreeNode encode(Node root) {
    if (root == null)
      return null;

    TreeNode rootTreeNode = new TreeNode(root.val);
    if (!root.children.isEmpty())
      rootTreeNode.left = encode(root.children.get(0));

    // The parent for the rest of the children
    TreeNode currTreeNode = rootTreeNode.left;

    // Encode the rest of the children
    for (int i = 1; i < root.children.size(); ++i) {
      currTreeNode.right = encode(root.children.get(i));
      currTreeNode = currTreeNode.right;
    }

    return rootTreeNode;
  }

  // Decodes your binary tree to an n-ary tree.
  public Node decode(TreeNode root) {
    if (root == null)
      return null;

    Node rootNode = new Node(root.val, new ArrayList<>());
    TreeNode currTreeNode = root.left;

    while (currTreeNode != null) {
      rootNode.children.add(decode(currTreeNode));
      currTreeNode = currTreeNode.right;
    }

    return rootNode;
  }
}
