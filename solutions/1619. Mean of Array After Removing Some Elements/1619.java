class Solution {
  public double trimMean(int[] arr) {
    Arrays.sort(arr);
    final int offset = arr.length / 20;
    return Arrays.stream(Arrays.copyOfRange(arr, offset, arr.length - offset)).average().orElse(0);
  }
}
