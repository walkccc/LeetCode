class Solution {
  public int lengthOfLongestSubstringKDistinct(String s, int k) {
    int ans = 0;
    int[] count = new int[128];

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (++count[s.charAt(r)] == 1)
        --k;
      while (k == -1)
        if (--count[s.charAt(l++)] == 0)
          ++k;
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}