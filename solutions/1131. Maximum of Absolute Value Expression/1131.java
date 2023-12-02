class Solution {
  public int maxAbsValExpr(int[] arr1, int[] arr2) {
    final int n = arr1.length;
    int[] a = new int[n];
    int[] b = new int[n];
    int[] c = new int[n];
    int[] d = new int[n];

    for (int i = 0; i < n; ++i) {
      a[i] = arr1[i] + arr2[i] + i;
      b[i] = arr1[i] + arr2[i] - i;
      c[i] = arr1[i] - arr2[i] + i;
      d[i] = arr1[i] - arr2[i] - i;
    }

    return Math.max(Math.max(diff(a), diff(b)), Math.max(diff(c), diff(d)));
  }

  private int diff(int[] nums) {
    final int min = Arrays.stream(nums).min().getAsInt();
    final int max = Arrays.stream(nums).max().getAsInt();
    return max - min;
  }
}
