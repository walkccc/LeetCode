public class Solution {
  public int findMaxK(int[] nums) {
    int ans = -1;
    Set<Integer> seen = new HashSet<>();

    for (final int num : nums)
      if (seen.contains(-num))
        ans = Math.max(ans, Math.abs(num));
      else
        seen.add(num);

    return ans;
  }
}
