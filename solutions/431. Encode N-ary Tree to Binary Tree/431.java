class Codec {
  // Encodes an n-ary tree to a binary tree.
  public TreeNode encode(Node root) {
    if (root == null)
      return null;

    TreeNode rootTreeNode = new TreeNode(root.val);
    Queue<Pair<Node, TreeNode>> q = new ArrayDeque<>(List.of(new Pair<>(root, rootTreeNode)));

    while (!q.isEmpty()) {
      Node parentNode = q.peek().getKey();
      TreeNode parentTreeNode = q.poll().getValue();
      TreeNode prevTreeNode = null;
      TreeNode headTreeNode = null;
      for (Node child : parentNode.children) {
        TreeNode currTreeNode = new TreeNode(child.val);
        if (prevTreeNode == null)
          headTreeNode = currTreeNode;
        else
          prevTreeNode.right = currTreeNode;
        prevTreeNode = currTreeNode;
        q.offer(new Pair<>(child, currTreeNode));
      }
      parentTreeNode.left = headTreeNode;
    }

    return rootTreeNode;
  }

  // Decodes your binary tree to an n-ary tree.
  public Node decode(TreeNode root) {
    if (root == null)
      return null;

    Node rootNode = new Node(root.val, new ArrayList<>());
    Queue<Pair<Node, TreeNode>> q = new ArrayDeque<>(List.of(new Pair<>(rootNode, root)));

    while (!q.isEmpty()) {
      Node parentNode = q.peek().getKey();
      TreeNode parentTreeNode = q.poll().getValue();
      TreeNode sibling = parentTreeNode.left;
      while (sibling != null) {
        Node currNode = new Node(sibling.val, new ArrayList<>());
        parentNode.children.add(currNode);
        q.offer(new Pair<>(currNode, sibling));
        sibling = sibling.right;
      }
    }

    return rootNode;
  }
}
