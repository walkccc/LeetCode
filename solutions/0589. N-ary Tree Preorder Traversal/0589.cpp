class Solution {
 public:
  vector<int> preorder(Node* root) {
    if (!root)
      return {};

    vector<int> ans;
    stack<Node*> stack{{root}};

    while (!stack.empty()) {
      root = stack.top(), stack.pop();
      ans.push_back(root->val);
      for (auto it = rbegin(root->children); it != rend(root->children); ++it)
        stack.push(*it);
    }

    return ans;
  }
};
