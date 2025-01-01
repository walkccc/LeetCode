class Solution {
  public int countPairs(int[] nums, int k) {
    int ans = 0;
    Map<Integer, List<Integer>> numToIndices = new HashMap<>();

    for (int i = 0; i < nums.length; ++i) {
      numToIndices.putIfAbsent(nums[i], new ArrayList<>());
      numToIndices.get(nums[i]).add(i);
    }

    for (List<Integer> indices : numToIndices.values()) {
      Map<Integer, Integer> gcds = new HashMap<>();
      for (final int i : indices) {
        final int gcd_i = gcd(i, k);
        for (final int gcd_j : gcds.keySet())
          if (gcd_i * gcd_j % k == 0)
            ans += gcds.get(gcd_j);
        gcds.merge(gcd_i, 1, Integer::sum);
      }
    }

    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
