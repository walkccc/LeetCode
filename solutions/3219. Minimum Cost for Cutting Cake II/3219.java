class Solution {
  // Same as 3218. Minimum Cost for Cutting Cake I
  public long minimumCost(int m, int n, int[] horizontalCut, int[] verticalCut) {
    long cost = 0;
    long sumH = Arrays.stream(horizontalCut).asLongStream().sum();
    long sumV = Arrays.stream(verticalCut).asLongStream().sum();

    Arrays.sort(horizontalCut);
    Arrays.sort(verticalCut);

    for (int i = m - 2, j = n - 2; i >= 0 && j >= 0;)
      if (horizontalCut[i] > verticalCut[j]) {
        cost += horizontalCut[i] + sumV;
        sumH -= horizontalCut[i--];
      } else {
        cost += verticalCut[j] + sumH;
        sumV -= verticalCut[j--];
      }

    return cost + sumH + sumV;
  }
}
