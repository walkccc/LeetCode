class Solution {
  public int[] diStringMatch(String S) {
    final int n = S.length();

    int[] ans = new int[n + 1];
    int min = 0;
    int max = n;

    for (int i = 0; i < n; ++i)
      ans[i] = S.charAt(i) == 'I' ? min++ : max--;
    ans[n] = min;

    return ans;
  }
}
