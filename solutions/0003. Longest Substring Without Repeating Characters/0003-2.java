class Solution {
  public int lengthOfLongestSubstring(String s) {
    int ans = 0;
    int j = -1;                    // s[j + 1..i] has no repeating chars.
    int[] lastSeen = new int[128]; // lastSeen[c] := index of last c appeared
    Arrays.fill(lastSeen, -1);

    for (int i = 0; i < s.length(); ++i) {
      // Update j to lastSeen[c], so the window must start from j + 1.
      j = Math.max(j, lastSeen[s.charAt(i)]);
      ans = Math.max(ans, i - j);
      lastSeen[s.charAt(i)] = i;
    }

    return ans;
  }
}
