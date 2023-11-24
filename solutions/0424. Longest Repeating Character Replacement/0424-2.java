class Solution {
  public int characterReplacement(String s, int k) {
    int ans = 0;
    int maxCount = 0;
    int[] count = new int[128];

    // l and r track max window instead of valid window.
    int l = 0;
    int r = 0;

    for (r = 0; r < s.length(); ++r) {
      maxCount = Math.max(maxCount, ++count[s.charAt(r)]);
      if (maxCount + k < r - l + 1)
        --count[s.charAt(l++)];
    }

    return r - l;
  }
}
