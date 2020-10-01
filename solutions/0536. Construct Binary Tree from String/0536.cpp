class Solution {
 public:
  TreeNode* str2tree(string s) {
    if (s.empty()) return nullptr;

    int i = -1;

    return str2tree(s, i);
  }

 private:
  TreeNode* str2tree(const string& s, int& i) {
    const int l = i + 1;
    const int r = getRight(s, l + 1);
    const int val = stoi(s.substr(l, r - l));

    TreeNode* root = new TreeNode(val);

    i = r;
    if (s[i] == '(') {
      root->left = str2tree(s, i);
      if (s[i] == '(')
        root->right = str2tree(s, i);
    }
    ++i;

    return root;
  }

  int getRight(const string& s, int r) {
    while (r < s.length() && isdigit(s[r]))
      ++r;
    return r;
  }
};