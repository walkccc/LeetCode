class Solution {
  public long appealSum(String s) {
    long ans = 0;
    int dp = 0; // # of appeal of string ending at current index
    int[] lastOccurrence = new int[26];
    Arrays.fill(lastOccurrence, -1);

    for (int i = 0; i < s.length(); ++i) {
      dp += i - lastOccurrence[s.charAt(i) - 'a'];
      ans += dp;
      lastOccurrence[s.charAt(i) - 'a'] = i;
    }

    return ans;
  }
}
