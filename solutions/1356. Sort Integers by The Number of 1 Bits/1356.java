class Solution {
  public int[] sortByBits(int[] arr) {
    Integer[] boxedArr = Arrays.stream(arr).boxed().toArray(Integer[] ::new);
    Arrays.sort(boxedArr, Comparator.comparingInt(Integer::bitCount).thenComparingInt(a -> a));
    return Arrays.stream(boxedArr).mapToInt(Integer::intValue).toArray();
  }
}
