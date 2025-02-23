class Solution {
  public int uniqueLetterString(String s) {
    int ans = 0;
    // the number of unique letters in all the substrings ending in the index so
    // far
    int dp = 0;
    int[] lastCount = new int[26];
    int[] lastSeen = new int[26];
    Arrays.fill(lastSeen, -1);

    for (int i = 0; i < s.length(); ++i) {
      final int c = s.charAt(i) - 'A';
      final int newCount = i - lastSeen[c];
      // Substract the duplicates.
      dp -= lastCount[c];
      // Add count of s[lastSeen[c] + 1..i], s[lastSeen[c] + 2..i], ..., s[i].
      dp += newCount;
      lastCount[c] = newCount;
      lastSeen[c] = i;
      ans += dp;
    }

    return ans;
  }
}
