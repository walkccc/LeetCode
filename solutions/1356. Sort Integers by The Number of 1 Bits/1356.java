class Solution {
  public int[] sortByBits(int[] arr) {
    Integer[] A = Arrays.stream(arr).boxed().toArray(Integer[] ::new);
    Arrays.sort(A,
                (a, b)
                    -> Integer.bitCount(a) == Integer.bitCount(b)
                           ? a - b
                           : Integer.bitCount(a) - Integer.bitCount(b));
    return Arrays.stream(A).mapToInt(i -> i).toArray();
  }
}
