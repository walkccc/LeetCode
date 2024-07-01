class Solution {
  public int mostFrequentEven(int[] nums) {
    int ans = -1;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int num : nums) {
      if (num % 2 == 1)
        continue;
      final int newCount = count.merge(num, 1, Integer::sum);
      final int maxCount = count.getOrDefault(ans, 0);
      if (newCount > maxCount || newCount == maxCount && num < ans)
        ans = num;
    }

    return ans;
  }
}
