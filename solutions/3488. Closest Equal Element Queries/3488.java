class Solution {
  public List<Integer> solveQueries(int[] nums, int[] queries) {
    final int n = nums.length;
    List<Integer> ans = new ArrayList<>();
    // minDist[i] := the minimum distance between nums[i], and any other index j in the circular
    // array, where nums[j] == nums[i]
    int[] minDist = new int[n];
    Arrays.fill(minDist, n);
    Map<Integer, Integer> lastSeen = new HashMap<>();

    for (int i = 0; i < n * 2; ++i) {
      final int index = i % n;
      final int num = nums[index];
      if (lastSeen.containsKey(num)) {
        final int prevIndex = lastSeen.get(num) % n;
        final int d = i - prevIndex;
        minDist[index] = Math.min(minDist[index], d);
        minDist[prevIndex] = Math.min(minDist[prevIndex], d);
      }
      lastSeen.put(num, i);
    }

    for (final int query : queries)
      ans.add(minDist[query] == n ? -1 : minDist[query]);

    return ans;
  }
}
