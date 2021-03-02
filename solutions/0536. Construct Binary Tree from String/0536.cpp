class Solution {
 public:
  TreeNode* str2tree(string s) {
    if (s.empty())
      return nullptr;
    int i = 0;
    return str2tree(s, i);
  }

 private:
  TreeNode* str2tree(const string& s, int& i) {
    const int start = i;  // start index of val
    if (s[i] == '-')
      ++i;
    while (i < s.length() && isdigit(s[i]))
      ++i;

    const int val = stoi(s.substr(start, i - start));
    TreeNode* root = new TreeNode(val);

    // left child
    if (i < s.length() && s[i] == '(') {
      ++i;  // '('
      root->left = str2tree(s, i);
      ++i;  // ')'
    }

    // right child
    if (i < s.length() && s[i] == '(') {
      ++i;  // '('
      root->right = str2tree(s, i);
      ++i;  // ')'
    }

    return root;
  }
};
