class Solution {
  public int lengthOfLongestSubstringTwoDistinct(String s) {
    int ans = 0;
    int distinct = 0;
    int[] count = new int[128];

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (++count[s.charAt(r)] == 1)
        ++distinct;
      while (distinct == 3)
        if (--count[s.charAt(l++)] == 0)
          --distinct;
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}
