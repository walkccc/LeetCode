class Solution {
  public int[] diStringMatch(String s) {
    final int n = s.length();
    int[] ans = new int[n + 1];
    int mn = 0;
    int mx = n;

    for (int i = 0; i < n; ++i)
      ans[i] = s.charAt(i) == 'I' ? mn++ : mx--;
    ans[n] = mn;

    return ans;
  }
}
