class Solution {
  public int maxTotalFruits(int[][] fruits, int startPos, int k) {
    final int maxRight = Math.max(startPos, fruits[fruits.length - 1][0]);
    int ans = 0;
    int[] amounts = new int[1 + maxRight];
    int[] prefix = new int[2 + maxRight];

    for (int[] f : fruits)
      amounts[f[0]] = f[1];

    for (int i = 0; i + 1 < prefix.length; ++i)
      prefix[i + 1] = prefix[i] + amounts[i];

    // go right first
    final int maxRightSteps = Math.min(maxRight - startPos, k);
    for (int rightSteps = 0; rightSteps <= maxRightSteps; ++rightSteps) {
      final int leftSteps = Math.max(0, k - 2 * rightSteps); // turn left
      ans = Math.max(ans, getFruits(startPos, maxRight, leftSteps, rightSteps, prefix));
    }

    // go left first
    final int maxLeftSteps = Math.min(startPos, k);
    for (int leftSteps = 0; leftSteps <= maxLeftSteps; ++leftSteps) {
      final int rightSteps = Math.max(0, k - 2 * leftSteps); // turn right
      ans = Math.max(ans, getFruits(startPos, maxRight, leftSteps, rightSteps, prefix));
    }

    return ans;
  }

  private int getFruits(int startPos, int maxRight, int leftSteps, int rightSteps, int[] prefix) {
    final int l = Math.max(0, startPos - leftSteps);
    final int r = Math.min(maxRight, startPos + rightSteps);
    return prefix[r + 1] - prefix[l];
  }
}
