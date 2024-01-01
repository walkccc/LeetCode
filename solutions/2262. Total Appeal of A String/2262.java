class Solution {
  public long appealSum(String s) {
    long ans = 0;
    // the total appeal of all substrings ending in the index so far
    int dp = 0;
    int[] lastSeen = new int[26];
    Arrays.fill(lastSeen, -1);

    for (int i = 0; i < s.length(); ++i) {
      //   the total appeal of all substrings ending in s[i]
      // = the total appeal of all substrings ending in s[i - 1]
      // + the number of substrings ending in s[i] that contain only this s[i]
      final int c = s.charAt(i) - 'a';
      dp += i - lastSeen[c];
      ans += dp;
      lastSeen[c] = i;
    }

    return ans;
  }
}
