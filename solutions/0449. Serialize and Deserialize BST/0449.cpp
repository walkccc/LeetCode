class Codec {
 public:
  string serialize(TreeNode* root) {
    if (root == nullptr)
      return "";

    string s;

    serialize(root, s);
    return s;
  }

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

  TreeNode* deserialize(int min, int max, queue<int>& q) {
    if (q.empty())
      return nullptr;

    const int val = q.front();
    if (val < min || val > max)
      return nullptr;

    q.pop();
    TreeNode* root = new TreeNode(val);
    root->left = deserialize(min, val, q);
    root->right = deserialize(val, max, q);
    return root;
  }
};
