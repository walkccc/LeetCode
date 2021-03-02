class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root)
      return "";

    string s;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (node) {
        s += to_string(node->val) + " ";
        q.push(node->left);
        q.push(node->right);
      } else {
        s += "n ";
      }
    }

    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty())
      return nullptr;

    istringstream iss(data);
    string word;
    iss >> word;
    TreeNode* root = new TreeNode(stoi(word));
    queue<TreeNode*> q{{root}};

    while (iss >> word) {
      TreeNode* parent = q.front();
      q.pop();
      if (word != "n") {
        TreeNode* left = new TreeNode(stoi(word));
        parent->left = left;
        q.push(left);
      }
      iss >> word;
      if (word != "n") {
        TreeNode* right = new TreeNode(stoi(word));
        parent->right = right;
        q.push(right);
      }
    }

    return root;
  }
};

