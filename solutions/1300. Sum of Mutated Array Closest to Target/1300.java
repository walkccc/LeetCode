class Solution {
  public int findBestValue(int[] arr, int target) {
    final int n = arr.length;
    final double err = 1e-9;

    int prefixSum = 0;

    Arrays.sort(arr);

    for (int i = 0; i < n; ++i) {
      int ans = (int) Math.round(((float) target - prefixSum - err) / (n - i));
      if (ans <= arr[i])
        return ans;
      prefixSum += arr[i];
    }

    return arr[n - 1];
  }
}