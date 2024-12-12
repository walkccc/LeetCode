class Solution {
  public int maximumLength(int[] nums) {
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    Map<Integer, Integer> count = new HashMap<>();

    for (final int num : nums)
      count.merge(num, 1, Integer::sum);

    int ans = count.containsKey(1) ? count.get(1) - (count.get(1) % 2 == 0 ? 1 : 0) : 1;

    for (final int num : nums) {
      if (num == 1)
        continue;
      int length = 0;
      long x = num;
      while (x <= maxNum && count.containsKey((int) x) && count.get((int) x) >= 2) {
        length += 2;
        x *= x;
      }
      // x is now x^k, and the pattern is [x, ..., x^(k/2), x^(k/2), ..., x].
      // The goal is to determine if we can insert x^k in the middle of the
      // pattern to increase the length by 1. If not, we make x^(k/2) the middle
      // and decrease the length by 1.
      ans = Math.max(ans, length + (count.containsKey((int) x) ? 1 : -1));
    }

    return ans;
  }
}
