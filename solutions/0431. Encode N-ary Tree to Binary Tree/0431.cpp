class Codec {
 public:
  // Encodes an n-ary tree to a binary tree.
  TreeNode* encode(Node* root) {
    if (root == nullptr)
      return nullptr;

    TreeNode* rootTreeNode = new TreeNode(root->val);
    queue<pair<Node*, TreeNode*>> q{{{root, rootTreeNode}}};

    while (!q.empty()) {
      const auto [parentNode, parentTreeNode] = q.front();
      q.pop();
      TreeNode* prevTreeNode = nullptr;
      TreeNode* headTreeNode = nullptr;
      for (Node* child : parentNode->children) {
        TreeNode* currTreeNode = new TreeNode(child->val);
        if (prevTreeNode != nullptr)
          prevTreeNode->right = currTreeNode;
        else
          headTreeNode = currTreeNode;
        prevTreeNode = currTreeNode;
        q.emplace(child, currTreeNode);
      }
      parentTreeNode->left = headTreeNode;
    }

    return rootTreeNode;
  }

  // Decodes your binary tree to an n-ary tree.
  Node* decode(TreeNode* root) {
    if (root == nullptr)
      return nullptr;

    Node* rootNode = new Node(root->val);
    queue<pair<Node*, TreeNode*>> q{{{rootNode, root}}};

    while (!q.empty()) {
      const auto [parentNode, parentTreeNode] = q.front();
      q.pop();
      TreeNode* sibling = parentTreeNode->left;
      while (sibling) {
        Node* currNode = new Node(sibling->val);
        parentNode->children.push_back(currNode);
        q.emplace(currNode, sibling);
        sibling = sibling->right;
      }
    }

    return rootNode;
  }
};
