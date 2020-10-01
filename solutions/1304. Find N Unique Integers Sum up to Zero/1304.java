class Solution {
  public int[] sumZero(int n) {
    int[] ans = new int[n];

    for (int i = 0; i < n; ++i)
      ans[i] = i * 2 - n + 1;

    return ans;
  }
}