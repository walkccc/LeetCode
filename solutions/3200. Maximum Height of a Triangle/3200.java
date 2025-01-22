class Solution {
  public int maxHeightOfTriangle(int red, int blue) {
    return Math.max(maxHeight(red, blue), maxHeight(blue, red));
  }

  // Returns the maximum height of a triangle with the odd levels having `n1`
  // balls and the even levels having `n2` balls.
  private int maxHeight(int n1, int n2) {
    //             1 + 3 + ... + h <= n1
    // ((1 + h) * (n + 1) / 2) / 2 <= n1
    //                           h <= sqrt(4 * n1) - 1
    final int oddHeight = (int) Math.sqrt(4 * n1) - 1;
    //       2 + 4 + ... + h <= n2
    // ((2 + h) * h / 2) / 2 <= n2
    //                     h <= sqrt(4 * n2 + 1) - 1
    final int evenHeight = (int) Math.sqrt(4 * n2 + 1) - 1;
    // If the difference between the odd and even heights is >= 1, we can add an
    // extra level to the minimum height.
    return Math.min(oddHeight, evenHeight) + (Math.abs(oddHeight - evenHeight) >= 1 ? 1 : 0);
  }
}
