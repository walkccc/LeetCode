class Solution {
  public long maxStrength(int[] nums) {
    long posProd = 1;
    long negProd = 1;
    int maxNeg = Integer.MIN_VALUE;
    int negCount = 0;
    boolean hasPos = false;
    boolean hasZero = false;

    for (final int num : nums)
      if (num > 0) {
        posProd *= num;
        hasPos = true;
      } else if (num < 0) {
        negProd *= num;
        maxNeg = Math.max(maxNeg, num);
        ++negCount;
      } else { // num == 0
        hasZero = true;
      }

    if (negCount == 0 && !hasPos)
      return 0;
    if (negCount % 2 == 0)
      return negProd * posProd;
    if (negCount >= 3)
      return negProd / maxNeg * posProd;
    if (hasPos)
      return posProd;
    if (hasZero)
      return 0;
    return maxNeg;
  }
}
