class Solution {
  public int smallestRangeI(int[] A, int K) {
    int max = Arrays.stream(A).max().getAsInt();
    int min = Arrays.stream(A).min().getAsInt();

    return Math.max(0, max - min - 2 * K);
  }
}
