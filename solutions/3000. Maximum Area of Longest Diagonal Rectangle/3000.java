class Solution {
  public int areaOfMaxDiagonal(int[][] dimensions) {
    int[] maxDimension =
        Arrays.stream(dimensions)
            .max((a, b)
                     -> a[0] * a[0] + a[1] * a[1] == b[0] * b[0] + b[1] * b[1]
                            ? Integer.compare(a[0] * a[1], b[0] * b[1])
                            : Integer.compare(a[0] * a[0] + a[1] * a[1], b[0] * b[0] + b[1] * b[1]))
            .orElseThrow();
    return maxDimension[0] * maxDimension[1];
  }
}
