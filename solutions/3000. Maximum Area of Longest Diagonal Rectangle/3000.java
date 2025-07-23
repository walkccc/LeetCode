class Solution {
  public int areaOfMaxDiagonal(int[][] dimensions) {
    int[] maxDimension = Arrays.stream(dimensions)
                             .max(Comparator.comparingInt((int[] d) -> d[0] * d[0] + d[1] * d[1])
                                      .thenComparingInt((int[] d) -> d[0] * d[1]))

                             .orElseThrow();
    return maxDimension[0] * maxDimension[1];
  }
}
