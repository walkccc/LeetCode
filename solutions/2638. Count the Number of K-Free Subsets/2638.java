class Solution {
  public long countTheNumOfKFreeSubsets(int[] nums, int k) {
    Map<Integer, Set<Integer>> modToSubset = new HashMap<>();

    for (final int num : nums) {
      modToSubset.putIfAbsent(num % k, new TreeSet<>());
      modToSubset.get(num % k).add(num);
    }

    int prevNum = -k;
    long skip = 0;
    long pick = 0;

    for (Set<Integer> subset : modToSubset.values())
      for (final int num : subset) {
        final long cacheSkip = skip;
        skip += pick;
        pick = 1 + cacheSkip + (num - prevNum == k ? 0 : pick);
        prevNum = num;
      }

    return 1 + skip + pick;
  }
}
