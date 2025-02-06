class Codec {
 public:
  // Encodes an n-ary tree to a binary tree.
  TreeNode* encode(Node* root) {
    if (root == nullptr)
      return nullptr;

    TreeNode* rootTreeNode = new TreeNode(root->val);
    if (!root->children.empty())
      rootTreeNode->left = encode(root->children[0]);

    // The parent for the rest of the children
    TreeNode* currTreeNode = rootTreeNode->left;

    // Encode the rest of the children
    for (int i = 1; i < root->children.size(); ++i) {
      currTreeNode->right = encode(root->children[i]);
      currTreeNode = currTreeNode->right;
    }

    return rootTreeNode;
  }

  // Decodes your binary tree to an n-ary tree.
  Node* decode(TreeNode* root) {
    if (root == nullptr)
      return nullptr;

    Node* rootNode = new Node(root->val);
    TreeNode* currTreeNode = root->left;

    while (currTreeNode != nullptr) {
      rootNode->children.push_back(decode(currTreeNode));
      currTreeNode = currTreeNode->right;
    }

    return rootNode;
  }
};
