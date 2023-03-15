class Solution {
  public int numKLenSubstrNoRepeats(String s, int k) {
    int ans = 0;
    int unique = 0;
    int[] count = new int[26];

    for (int i = 0; i < s.length(); ++i) {
      if (++count[s.charAt(i) - 'a'] == 1)
        ++unique;
      if (i >= k && --count[s.charAt(i - k) - 'a'] == 0)
        --unique;
      if (unique == k)
        ++ans;
    }

    return ans;
  }
}
