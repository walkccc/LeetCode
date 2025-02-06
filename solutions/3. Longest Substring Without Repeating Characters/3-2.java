class Solution {
  public int lengthOfLongestSubstring(String s) {
    int ans = 0;
    // The substring s[j + 1..i] has no repeating characters.
    int j = -1;
    // lastSeen[c] := the index of the last time c appeared
    int[] lastSeen = new int[128];
    Arrays.fill(lastSeen, -1);

    for (int i = 0; i < s.length(); ++i) {
      // Update j to lastSeen[s.charAt(i)], so the window must start from j + 1.
      j = Math.max(j, lastSeen[s.charAt(i)]);
      ans = Math.max(ans, i - j);
      lastSeen[s.charAt(i)] = i;
    }

    return ans;
  }
}
