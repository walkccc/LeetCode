class Solution {
  public int findBestValue(int[] arr, int target) {
    final int n = arr.length;
    final double err = 1e-9;

    int prefix = 0;

    Arrays.sort(arr);

    for (int i = 0; i < n; ++i) {
      int ans = (int) Math.round(((float) target - prefix - err) / (n - i));
      if (ans <= arr[i])
        return ans;
      prefix += arr[i];
    }

    return arr[n - 1];
  }
}
