class Solution {
  public int maxGoodNumber(int[] nums) {
    int ans = 0;
    Integer[] A = Arrays.stream(nums).boxed().toArray(Integer[] ::new);

    Arrays.sort(A, (a, b) -> Integer.compare(concat(b, a), concat(a, b)));

    for (final int a : A)
      ans = concat(ans, a);

    return ans;
  }

  // Returns the concatenation of the binary representations of a and b.
  private int concat(int a, int b) {
    return a * (Integer.highestOneBit(b) << 1) + b;
  }
}
