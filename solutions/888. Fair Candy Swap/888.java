class Solution {
  public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
    final int diff = (Arrays.stream(aliceSizes).sum() - Arrays.stream(bobSizes).sum()) / 2;
    Set<Integer> bobSizesSet = Arrays.stream(bobSizes).boxed().collect(Collectors.toSet());

    for (final int aliceSize : aliceSizes) {
      final int target = aliceSize - diff;
      if (bobSizesSet.contains(target))
        return new int[] {aliceSize, target};
    }

    throw new IllegalArgumentException();
  }
}
