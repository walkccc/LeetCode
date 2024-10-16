class Solution {
 public:
  vector<int> postorder(Node* root) {
    if (root == nullptr)
      return {};

    vector<int> ans;
    stack<Node*> stack{{root}};

    while (!stack.empty()) {
      root = stack.top(), stack.pop();
      ans.push_back(root->val);
      for (Node* child : root->children)
        stack.push(child);
    }

    ranges::reverse(ans);
    return ans;
  }
};
