class Solution {
  public boolean isPossibleToSplit(int[] nums) {
    final int kMax = 100;
    int[] count = new int[kMax + 1];

    for (final int num : nums)
      ++count[num];

    return Arrays.stream(count).allMatch(freq -> freq <= 2);
  }
}
