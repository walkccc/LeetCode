class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr)
      return "";
    string s;
    serialize(root, s);
    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty())
      return nullptr;

    istringstream iss(data);
    queue<int> q;

    for (string s; iss >> s;)
      q.push(stoi(s));

    return deserialize(INT_MIN, INT_MAX, q);
  }

 private:
  void serialize(TreeNode* root, string& s) {
    if (root == nullptr)
      return;
    s += to_string(root->val) + " ";
    serialize(root->left, s);
    serialize(root->right, s);
  }

  TreeNode* deserialize(int mn, int mx, queue<int>& q) {
    if (q.empty())
      return nullptr;

    const int val = q.front();
    if (val < mn || val > mx)
      return nullptr;

    q.pop();
    TreeNode* root = new TreeNode(val);
    root->left = deserialize(mn, val, q);
    root->right = deserialize(val, mx, q);
    return root;
  }
};
