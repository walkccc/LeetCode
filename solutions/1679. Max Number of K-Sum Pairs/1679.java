class Solution {
  public int maxOperations(int[] nums, int k) {
    int ans = 0;
    HashMap<Integer, Integer> count = new HashMap<>();

    for (final int num : nums)
      count.merge(num, 1, Integer::sum);

    for (final int num : count.keySet()) {
      final int complement = k - num;
      if (count.containsKey(complement))
        ans += Math.min(count.get(num), count.get(complement));
    }

    return ans / 2;
  }
}
