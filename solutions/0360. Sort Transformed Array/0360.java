class Solution {
  public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
    final int n = nums.length;
    final boolean upward = a > 0;
    int[] ans = new int[n];
    int[] quad = new int[n];

    for (int i = 0; i < nums.length; ++i)
      quad[i] = f(nums[i], a, b, c);

    int i = upward ? n - 1 : 0;
    for (int l = 0, r = n - 1; l <= r;)
      if (upward) // maximum in both ends
        ans[i--] = quad[l] > quad[r] ? quad[l++] : quad[r--];
      else // minimum in both ends
        ans[i++] = quad[l] < quad[r] ? quad[l++] : quad[r--];

    return ans;
  }

  // the concavity of f only depends on a's sign
  private int f(int x, int a, int b, int c) {
    return (a * x + b) * x + c;
  }
}
