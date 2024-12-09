class Solution {
  public boolean isValidSerialization(String preorder) {
    int degree = 1; // out-degree (children) - in-degree (parent)

    for (final String node : preorder.split(",")) {
      if (--degree < 0) // One parent
        return false;
      if (!node.equals("#"))
        degree += 2; // Two children
    }

    return degree == 0;
  }
}
