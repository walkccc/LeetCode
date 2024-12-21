class Solution {
  public boolean divideArray(int[] nums) {
    int[] count = new int[501];

    for (final int num : nums)
      ++count[num];

    return Arrays.stream(count).allMatch(c -> c % 2 == 0);
  }
}
