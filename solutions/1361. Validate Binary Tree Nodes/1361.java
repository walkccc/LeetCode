class Solution {
  public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
    int[] inDegrees = new int[n];
    int root = -1;

    // If the in-degree of any node > 1, return false.
    for (final int child : leftChild)
      if (child != -1 && ++inDegrees[child] == 2)
        return false;

    for (final int child : rightChild)
      if (child != -1 && ++inDegrees[child] == 2)
        return false;

    // Find the root (the node with in-degree == 0).
    for (int i = 0; i < n; ++i)
      if (inDegrees[i] == 0)
        if (root == -1)
          root = i;
        else
          return false; // There're multiple roots.

    // Didn't find the root.
    if (root == -1)
      return false;

    return countNodes(root, leftChild, rightChild) == n;
  }

  private int countNodes(int root, int[] leftChild, int[] rightChild) {
    if (root == -1)
      return 0;
    return 1 + //
        countNodes(leftChild[root], leftChild, rightChild) +
        countNodes(rightChild[root], leftChild, rightChild);
  }
}
