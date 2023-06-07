class Solution {
 public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                               vector<int>& rightChild) {
    vector<int> inDegree(n);
    int root = -1;

    // If inDegree of any node > 1, return false
    for (const int child : leftChild)
      if (child != -1 && ++inDegree[child] == 2)
        return false;

    for (const int child : rightChild)
      if (child != -1 && ++inDegree[child] == 2)
        return false;

    // Find the root (node with inDegree == 0)
    for (int i = 0; i < n; ++i)
      if (inDegree[i] == 0)
        if (root == -1)
          root = i;
        else
          return false;  // Multiple roots

    // didn't find the root
    if (root == -1)
      return false;

    return countNodes(root, leftChild, rightChild) == n;
  }

 private:
  int countNodes(int root, const vector<int>& leftChild,
                 const vector<int>& rightChild) {
    if (root == -1)
      return 0;
    return 1 +  //
           countNodes(leftChild[root], leftChild, rightChild) +
           countNodes(rightChild[root], leftChild, rightChild);
  }
};
