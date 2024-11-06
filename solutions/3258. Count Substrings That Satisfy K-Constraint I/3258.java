class Solution {
  public int countKConstraintSubstrings(String s, int k) {
    int ans = 0;
    int[] count = new int[2];

    int l = 0;
    for (int r = 0; r < s.length(); ++r) {
      ++count[s.charAt(r) - '0'];
      while (count[0] > k && count[1] > k)
        --count[s.charAt(l++) - '0'];
      ans += r - l + 1;
    }

    return ans;
  }
}
