class Solution {
 public:
  TreeNode* recoverFromPreorder(string S) {
    int i = 0;
    return recoverFromPreorder(S, 0, i);
  }

 private:
  TreeNode* recoverFromPreorder(const string& S, int depth, int& i) {
    int nDashes = 0;
    while (i + nDashes < S.length() && S[i + nDashes] == '-')
      ++nDashes;
    if (nDashes != depth)
      return nullptr;

    i += depth;
    const int start = i;
    while (i < S.length() && isdigit(S[i]))
      ++i;

    const int val = stoi(S.substr(start, i - start));
    TreeNode* root = new TreeNode(val);

    root->left = recoverFromPreorder(S, depth + 1, i);
    root->right = recoverFromPreorder(S, depth + 1, i);

    return root;
  }
};
