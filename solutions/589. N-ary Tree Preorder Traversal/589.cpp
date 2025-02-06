class Solution {
 public:
  vector<int> preorder(Node* root) {
    if (root == nullptr)
      return {};

    vector<int> ans;
    stack<Node*> stack{{root}};

    while (!stack.empty()) {
      root = stack.top(), stack.pop();
      ans.push_back(root->val);
      for (auto it = root->children.rbegin(); it != root->children.rend(); ++it)
        stack.push(*it);
    }

    return ans;
  }
};
