class Solution {
  public int longestConsecutive(int[] nums) {
    int ans = 0;
    Set<Integer> set = new HashSet<>();

    for (final int num : nums)
      set.add(num);

    for (int num : nums)
      // the start num of a sequence
      if (!set.contains(num - 1)) {
        int length = 0;
        while (set.contains(num++))
          ++length;
        ans = Math.max(ans, length);
      }

    return ans;
  }
}