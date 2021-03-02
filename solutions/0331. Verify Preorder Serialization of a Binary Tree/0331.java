class Solution {
  public boolean isValidSerialization(String preorder) {
    int degree = 1; // outDegree (children) - inDegree (parent)

    for (final String node : preorder.split(",")) {
      if (--degree < 0) // one parent
        return false;
      if (!node.equals("#"))
        degree += 2; // two children
    }

    return degree == 0;
  }
}
