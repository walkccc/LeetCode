class Solution {
  public int minZeroArray(int[] nums, int[][] queries) {
    if (Arrays.stream(nums).allMatch(num -> num == 0))
      return 0;

    final int n = nums.length;
    Set<Integer>[] subsetSums = new Set[n];

    for (int i = 0; i < n; ++i)
      subsetSums[i] = new HashSet<>(List.of(0));

    for (int k = 0; k < queries.length; ++k) {
      final int l = queries[k][0];
      final int r = queries[k][1];
      final int val = queries[k][2];
      for (int i = l; i <= r; ++i) {
        List<Integer> sums = new ArrayList<>();
        for (final int subsetSum : subsetSums[i])
          sums.add(subsetSum + val);
        subsetSums[i].addAll(sums);
      }
      if (IntStream.range(0, n).allMatch(i -> subsetSums[i].contains(nums[i])))
        return k + 1;
    }

    return -1;
  }
}
