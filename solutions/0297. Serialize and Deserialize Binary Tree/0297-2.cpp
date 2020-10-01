class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string s;

    function<void(TreeNode*)> preorder = [&](TreeNode* root) {
      if (!root) {
        s += "n ";
        return;
      }
      s += to_string(root->val) + " ";
      preorder(root->left);
      preorder(root->right);
    };

    preorder(root);

    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream iss(data);
    queue<string> q;

    for (string s; iss >> s;)
      q.push(s);

    function<TreeNode*()> preorder = [&]() -> TreeNode* {
      const string s = q.front(); q.pop();
      if (s == "n") return nullptr;

      TreeNode* root = new TreeNode(stoi(s));
      root->left = preorder();
      root->right = preorder();

      return root;
    };

    return preorder();
  }
};