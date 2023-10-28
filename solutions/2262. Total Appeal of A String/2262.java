class Solution {
  public long appealSum(String s) {
    long ans = 0;
    // total appeal of all substrings ending at the index so far
    int dp = 0;
    int[] lastSeen = new int[26];
    Arrays.fill(lastSeen, -1);

    for (int i = 0; i < s.length(); ++i) {
      //   total appeal of all substrings ending at s[i]
      // = total appeal of all substrings ending at s[i - 1]
      // + # of substrings ending at s[i] that contain only this s[i]
      final int c = s.charAt(i) - 'a';
      dp += i - lastSeen[c];
      ans += dp;
      lastSeen[c] = i;
    }

    return ans;
  }
}
