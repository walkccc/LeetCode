class Solution {
 public:
  TreeNode* str2tree(string s) {
    if (s.empty())
      return nullptr;

    stack<TreeNode*> stack;

    for (int l = 0, r = 0; r < s.length(); l = ++r)
      if (s[r] == ')') {
        stack.pop();
      } else if (isdigit(s[r]) || s[r] == '-') {
        while (r + 1 < s.length() && isdigit(s[r + 1]))
          ++r;
        const int val = stoi(s.substr(l, r - l + 1));
        TreeNode* node = new TreeNode(val);
        if (!stack.empty()) {
          TreeNode* parent = stack.top();
          if (parent->left)
            parent->right = node;
          else
            parent->left = node;
        }
        stack.push(node);
      }

    return stack.top();
  }
};
