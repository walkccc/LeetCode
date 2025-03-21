class Solution {
 public:
  TreeNode* recoverFromPreorder(string traversal) {
    int i = 0;
    return recoverFromPreorder(traversal, 0, i);
  }

 private:
  TreeNode* recoverFromPreorder(const string& traversal, int depth, int& i) {
    int nDashes = 0;
    while (i + nDashes < traversal.length() && traversal[i + nDashes] == '-')
      ++nDashes;
    if (nDashes != depth)
      return nullptr;

    i += depth;
    const int start = i;
    while (i < traversal.length() && isdigit(traversal[i]))
      ++i;

    return new TreeNode(stoi(traversal.substr(start, i - start)),
                        recoverFromPreorder(traversal, depth + 1, i),
                        recoverFromPreorder(traversal, depth + 1, i));
  }
};
