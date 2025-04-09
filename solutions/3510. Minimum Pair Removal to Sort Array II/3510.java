class Solution {
  public int minimumPairRemoval(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    int inversionsCount = 0;
    int[] nextIndices = new int[n];
    int[] prevIndices = new int[n];
    long[] values = Arrays.stream(nums).mapToLong(i -> i).toArray();
    TreeSet<Pair<Long, Integer>> pairSums =
        new TreeSet<>(Comparator.comparingLong(Pair<Long, Integer>::getKey)
                          .thenComparingInt(Pair<Long, Integer>::getValue));

    for (int i = 0; i < n; ++i) {
      nextIndices[i] = i + 1;
      prevIndices[i] = i - 1;
    }

    for (int i = 0; i < n - 1; ++i)
      pairSums.add(new Pair<>((long) nums[i] + nums[i + 1], i));

    for (int i = 0; i < n - 1; ++i)
      if (nums[i + 1] < nums[i])
        ++inversionsCount;

    while (inversionsCount > 0) {
      ++ans;
      Pair<Long, Integer> smallestPair = pairSums.pollFirst();
      final long pairSum = smallestPair.getKey();
      final int currIndex = smallestPair.getValue();
      final int nextIndex = nextIndices[currIndex];
      final int prevIndex = prevIndices[currIndex];
      if (prevIndex >= 0) {
        final long oldPairSum = values[prevIndex] + values[currIndex];
        final long newPairSum = values[prevIndex] + pairSum;
        pairSums.remove(new Pair<>(oldPairSum, prevIndex));
        pairSums.add(new Pair<>(newPairSum, prevIndex));
        if (values[prevIndex] > values[currIndex])
          --inversionsCount;
        if (values[prevIndex] > pairSum)
          ++inversionsCount;
      }

      if (values[nextIndex] < values[currIndex])
        --inversionsCount;

      final int nextNextIndex = (nextIndex < n) ? nextIndices[nextIndex] : n;
      if (nextNextIndex < n) {
        final long oldPairSum = values[nextIndex] + values[nextNextIndex];
        final long newPairSum = pairSum + values[nextNextIndex];
        pairSums.remove(new Pair<>(oldPairSum, nextIndex));
        pairSums.add(new Pair<>(newPairSum, currIndex));
        if (values[nextNextIndex] < values[nextIndex])
          --inversionsCount;
        if (values[nextNextIndex] < pairSum)
          ++inversionsCount;
        prevIndices[nextNextIndex] = currIndex;
      }

      nextIndices[currIndex] = nextNextIndex;
      values[currIndex] = pairSum;
    }

    return ans;
  }
}
